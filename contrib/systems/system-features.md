### Unconditional

2token/token.maude: `step*` proofs, subsumed proof
choice/choice.maude: `step*` single-goal proof, uses case analysis

### Conditional initial state

rw/rw.maude: cinit (simple conditions), `step*` proofs, 2 multi-goal proof, 1 subsumed proof
bakery/bakery.maude: cinit, complicated case analysis proof

### Conditional rules

dijkstra/dijkstra.maude: crl, `step*` single-goal proof
qlock/qlock.maude: crl, cinit, `step*` proofs, multiple goals
thermostat/thermostat.maude: crl, cinit, `step*` proof
oc/oc.maude: crl (disequality check), `step*` proof, multiple goals

### No proofs

cr-imp/imp-orig.maude: crl (just for heating), no proofs
cr-imp/imp.maude: crl (just for heating), no proofs
cr-simp/swap.maude: `step*` proof, cinit, multiple goals
cr-simp/imp.maude: no conditional rules
cr-simp/mutex-imp.maude: no proofs
cr-simp/zmutex.maude: no proofs
