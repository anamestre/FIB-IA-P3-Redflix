(define (problem test-01) (:domain planificador)
    (:objects c1 c2 c3 c4 c5 - contenido
    		d1 d2 - dia)
    (:init
        (predecesor c1 c2)
        (predecesor c2 c3)
        (predecesor c4 c5)

        (ver c3)
        (ver c5)

        (visto c1)
        (dia d1)
        (dia d2)
    )

    (:goal (and (forall (?x - contenido) (not (ver ?x))) (forall (?n - dia) (dia ?n)))))


