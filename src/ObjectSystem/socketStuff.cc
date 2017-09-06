/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Main socket manipulation code.
//
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void
SocketManagerSymbol::doRead(int fd)
{
}

void
SocketManagerSymbol::doWrite(int fd)
{
}

void
SocketManagerSymbol::doError(int fd)
{
}

void
SocketManagerSymbol::doHungUp(int fd)
{
}

bool
SocketManagerSymbol::getPort(DagNode* portArg, int& port)
{
  return succSymbol->getSignedInt(portArg, port) && port <= 65535;  // HACK
}

bool
SocketManagerSymbol::getDomain(DagNode* domainArg, int& domain)
{
  if (domainArg->symbol() == stringSymbol)
    {
      if (safeCast(StringDagNode*, domainArg)->getValue() == crope("IPv4"))
	{
	  domain = PF_INET;
	  return true;
	}
    }
  return false;
}

bool
SocketManagerSymbol::getActiveSocket(DagNode* socketArg, int& socketId)
{
  if (socketArg->symbol() == socketOidSymbol)
    {
      DagNode* idArg = safeCast(FreeDagNode*, socketArg)->getArgument(0);
      if (succSymbol->getSignedInt(idArg, socketId) &&
	  activeSockets.find(socketId) != activeSockets.end())
	return true;
    }
  return false;
}

bool
SocketManagerSymbol::getText(DagNode* textArg, crope& text)
{
  if (textArg->symbol() == stringSymbol)
    {
      text = safeCast(StringDagNode*, textArg)->getValue();
      return true;
    }
  return false;
}

void
SocketManagerSymbol::errorReply(const char* errorMessage,
				FreeDagNode* originalMessage,
				ObjectSystemRewritingContext& context)
{
  Vector<DagNode*> reply(3);
  reply[1] = originalMessage->getArgument(0);
  reply[2] = new StringDagNode(stringSymbol, errorMessage);
  DagNode* target = originalMessage->getArgument(1);
  reply[0] = target;
  context.bufferMessage(target, socketErrorMsg->makeDagNode(reply));
}

bool
SocketManagerSymbol::createClientTcpSocket(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  Assert(message->getArgument(0)->symbol() == this, "misdirected message");
  int domain;
  int port;
  DagNode* addressArg = message->getArgument(3);

  if (getDomain(message->getArgument(2), domain) &&
      getPort(message->getArgument(4), port) &&
      addressArg->symbol() == stringSymbol)
    {
      //
      //	We accept the message.
      //

      //
      //	Look up the address.
      //
      const crope& address = safeCast(StringDagNode*, addressArg)->getValue();
      hostent* record = gethostbyname(address.c_str());  // HACK
      if (record == 0)
	{
	  errorReply("bad address", message, context);
	  return true;
	}
      //
      //	Create a socket.
      //
      int fd = socket(domain, SOCK_STREAM, 0);
      if (fd == -1)
	{
	  errorReply("system call problem", message, context);
	  return true;
	}
      /*
      //
      //	Make it non-blocking.
      //
      int flags = fcntl(fd, F_GETFL);
      if (flags == -1)
	{
	  errorReply("system call problem", message, context);
	  return true;
	}
      if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
	{
	  errorReply("system call problem", message, context);
	  return true;
	}
      */
      //
      //	Try to connect to host.
      //
      sockaddr_in sockName;
      sockName.sin_family = AF_INET;
      sockName.sin_port = htons(port);
      sockName.sin_addr = *(reinterpret_cast<in_addr*>(record->h_addr_list[0]));  // HACK
      if (connect(fd, reinterpret_cast<sockaddr*>(&sockName), sizeof(sockName)) == 0)
	{
	  //
	  //	Instant success
	  //
	  activeSockets[fd].state = READY_TO_SEND;
	  Vector<DagNode*> reply(1, 3);
	  reply[0] = succSymbol->makeNatDag(fd);
	  DagNode* socketName = socketOidSymbol->makeDagNode(reply);
	  context.addExternalObject(socketName, this);
	  reply.resize(3);
	  reply[2] = socketName;
	  reply[1] = message->getArgument(0);
	  DagNode* target = message->getArgument(1);
	  reply[0] = target;
	  context.bufferMessage(target, createdSocketMsg->makeDagNode(reply));
	  return true;
	}
      /*
      else if (errno == EINPROGRESS)
	state = WAITING_TO_CONNECT;  // potential delayed success
      */
      else
	{
	  close(fd);
	  errorReply("failed to connnect", message, context);
	  return true;
	}
    }
  return true;
}

bool
SocketManagerSymbol::createServerTcpSocket(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  Assert(message->getArgument(0)->symbol() == this, "misdirected message");
  return false;
}

bool
SocketManagerSymbol::acceptClient(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  return false;
}

bool
SocketManagerSymbol::send(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  int socketId;
  crope text;
  if (getActiveSocket(message->getArgument(0), socketId) &&
      getText(message->getArgument(2), text))
    {
      ssize_t n = write(socketId, text.c_str(), text.size());  // need to check how much was written
      if (n != text.size())
	errorReply("read failed", message, context);
      else
	{
	  Vector<DagNode*> reply(2);
	  DagNode* target = message->getArgument(1);
	  reply[0] = target;
	  reply[1] = message->getArgument(0);
	  context.bufferMessage(target, sentMsg->makeDagNode(reply));
	}
      return true;
    }
  return false;
}

void
SocketManagerSymbol::closeSocket(DagNode* socketName,
				 int socketId,
				 DagNode* clientName,
				 ObjectSystemRewritingContext& context)
{
  close(socketId);
  context.deleteExternalObject(socketName);
  activeSockets.erase(socketId);
  Vector<DagNode*> reply(2);
  reply[1] = socketName;
  DagNode* target = clientName;
  reply[0] = target;
  context.bufferMessage(target, closedSocketMsg->makeDagNode(reply));
}

bool
SocketManagerSymbol::receive(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  DagNode* socketName = message->getArgument(0);
  int socketId;
  char buffer[4096];  // HACK
  if (getActiveSocket(socketName, socketId))
    {
      ssize_t n = read(socketId, buffer, 4096);
      if (n == -1)
	errorReply("read failed", message, context);
      else if (n == 0)
	closeSocket(socketName, socketId, message->getArgument(1), context);
      else
	{
	  crope text(buffer, n);
	  Vector<DagNode*> reply(3);
	  reply[1] = message->getArgument(0);
	  reply[2] = new StringDagNode(stringSymbol, text);
	  DagNode* target = message->getArgument(1);
	  reply[0] = target;
	  context.bufferMessage(target, receivedMsg->makeDagNode(reply));
	}
      return true;
    }
  return false;
}

bool
SocketManagerSymbol::closeSocket(FreeDagNode* message, ObjectSystemRewritingContext& context)
{
  DagNode* socketName = message->getArgument(0);
  int socketId;
  if (getActiveSocket(socketName, socketId))
    {
      closeSocket(socketName, socketId, message->getArgument(1), context);
      return true;
    }
  return false;
}

void
SocketManagerSymbol::cleanUp(DagNode* objectId)
{
  int socketId;
  if (getActiveSocket(objectId, socketId))
    {
      DebugAdvisory("cleaning up " << objectId);
      close(socketId);
      activeSockets.erase(socketId);
    }
  else
    CantHappen("no socket for " << objectId);
}
