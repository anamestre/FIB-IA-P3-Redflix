
(define (problem contenido) 
  (:domain contenido)
  (:objects
     c1 c2 c3 c4 c5 c6 c7 c8 c9 c10 c11 c12 c13 c14 - contenido
    dia1 dia2 dia3 dia4 dia5 dia6 dia7 dia8 dia9 dia10 dia11 dia12 - dia
  )

  (:init
    (predecesor c2 c4)
    (predecesor c4 c3)
    (predecesor c2 c3)
    (predecesor c7 c6)
    (ver c3)
    (ver c2)
    (ver c7)
    
    (visto c6)
  ) 

  (:goal (and
            (quiero_ver c3)
            (quiero_ver c2)
            (quiero_ver c7)
         )
  )
)