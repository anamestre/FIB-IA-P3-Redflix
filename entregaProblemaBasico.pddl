(define (problem test-01) (:domain planificador)
    (:objects c1 c2 c3 c4 c5 - contenido)
    (:init
        (predecesor c1 c2)
        (predecesor c2 c3)
        (predecesor c4 c5)

        (ver c3)
        (ver c5)
    )

    (:goal (and (forall (?x - contenido) (ver ?x)))))