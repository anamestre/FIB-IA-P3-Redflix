(define (domain planificador)
    (:requirements :adl :typing)
    (:types contenido - item
            dia - item)
    (:functions
        (capacidadDia ?d - dia)           ;; Cuantos contenidos tiene asignado un dia.
        (ordenDia ?d - dia)               ;; le damos un valor a cada dia, para ver cuál va antes.
        (ultimoDia ?c - contenido)        ;; el ultimo dia que se le ha asignado a un predecesor de este contenido.
        (predecesores ?c - contenido)     ;; el num de predecesores que tiene cada contenido.
        (predecesoresAsignados ?c - contenido) ;; el num de predecesores de cada contenido que ya se ha asignado a un dia.
;;        (paralelos ?c - contenido))       ;; el num de paralelos que tiene cada contenido.
        (minutosDia ?d - dia)
        (minutosContenido ?c - contenido))
    (:predicates
        (predecesor ?x - contenido ?y - contenido)  ;;x precede a y
        (visto ?x - contenido)                 
        (ver ?x - contenido)
        (contenidoAsignado ?c - contenido))
;;        (paralelo ?x - contenido ?y - contenido)) ;; x es paralelo a y

    (:action ver_predecesor :parameters (?x - contenido ?y - contenido)
        :precondition (and (predecesor ?x ?y) (not (ver ?x)) (ver ?y))
        :effect (and (ver ?x) (increase (predecesores ?y) 1)))
        
;;    (:action ver_paralelo :parameters (?x - contenido ?y - contenido)
;;        :precondition (and (or(paralelo ?x ?y) (paralelo ?y ?x)) (not (ver ?x)) (ver ?y))
;;        :effect (and (ver ?x) (increase (paralelos ?y) 1) (increase (paralelos ?x), 1)))

    (:action ver_contenido :parameters (?x - contenido)
        :precondition (and (ver ?x) (forall (?y - contenido) (or (not (predecesor ?y ?x)) (visto ?y))))
        :effect (and (not (ver ?x)) (visto ?x)))
        
    (:action asignar_contenidos :parameters (?d - dia ?x - contenido)
        :precondition (and (ver ?x) (not (contenidoAsignado ?x)) (< (capacidadDia ?d) 3) (> (ordenDia ?d) (ultimoDia ?x)) 
                        (= (predecesores ?x) (predecesoresAsignados ?x)) 
                        (<= (+ (minutosDia ?d) (minutosContenido ?x)) 200))
        :effect  (and (increase (capacidadDia ?d) 1) (contenidoAsignado ?x) (increase (minutosDia ?d) (minutosContenido ?x))
                (forall (?y - contenido) (when (predecesor ?x ?y) (and (assign (ultimoDia ?y) (ordenDia ?d)) 
                (increase (predecesoresAsignados ?y) 1) )))))

)