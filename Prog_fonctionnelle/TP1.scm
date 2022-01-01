(define square
					;takes x as input and return x²
  (lambda (x)
    (* x x)))

(square 2)

(define quad
					;takes x as input and return x⁴
  (lambda(x)
    (* (square x) (square x))))

(quad 2)


(define PI 3.141519)

(define circle
					;takes r, the radius of a circle, and return a list with its circumference and surface.
  (lambda (r)
    (list (quote circumference:) (* PI (* 2 r)) (quote  surface: ) (* PI (* r r)))))

(circle 1)


(define LA
  '(1 (2 (6) (7)) (3 (8 12) (9)) (4 (10 (13) (14 (17))) (11 (15 16)) (18)) (5)))

(let ((L LA))
  (car LA))

(let ()
  (cdr LA))

					;subtree with 2 as root
(let ()
  (cadr LA))
					;subtree with 4 as root
(let ()
  (cadddr LA))

					;takes the leaf 14
(let ()
  (caar (cddadr (cadddr LA))))

					;return the subtree with 10 as root
(define subtreeWithRoot10
  (lambda()
   (cadr (cadddr LA))))

(subtreeWithRoot10)


(define subTree4
  (lambda()
    (car (cdddr LA))))

(subTree4)

(define addLeafEnd
					;To add a leaf we have to:
					;access to the end of the tree
					;add the leaf
					;rebuild the tree => recursivity
  
  (lambda (tree leaf)
    (if (null? tree)
	(list leaf)
	(cons (car tree) (addLeafEnd (cdr tree) leaf)))))

(addLeafEnd  (subTree4) 1)

				    

(define subTree8
  (lambda()
    (cadr(caddr LA))))

(subTree8)

(define addAfterRoot
  (lambda(L element)
    (if (null? L) ;it shouldn't be empty but we keep the good MANIERE MEC
	(quote "I won't do anything!")
	(cons (car L) (cons element (cdr L))))))


(addAfterRoot (subTree8) 81)
    


(define fac
					;Recursivity:
					;return 1 if n<1 else return n * fac(n-1)
  (lambda(n)
    (if (< n 1)
	1
	(* n (fac (- n 1))))))
(fac 3)

(define som_int
					;return the integers' sum from 0 to n
					;if n <= 0 return 0
					;else return n + (som_int n-1)
  
  (lambda(n)
    (if (<= n 0)
	0
	(+ n (som_int (- n 1))))))

(som_int 7)

(define sum_int
  (lambda(n)
    (cond ((< n 0)(quote "mauvaise valeur"))
	  ((> n 0)(+ n (sum_int (- n 1))))
	  (else 0))
    ))

(sum_int 2)

(define sum_int3
  (lambda(n)
    (/ (* (+ 1 n) n) 2) ))

(sum_int3 2)


(define long
					;case L = () => 0
					;else long L = [a | L'] = 1 + long L'
  (lambda (L)
    (if (null? L)
	0
	(+ 1 (long (cdr L)))) ))

(long '(1 2 3))



					;reverse a list
(define reverse
					;we will use an other empty List and add each time the head of our main list in the head of our 2nd until it is empty
  (lambda(L Lr)
    (if (null? L)
	Lr
	(reverse (cdr L) (cons (car L) Lr)))
    ))

(define useReverse
  (lambda(L)
    (reverse L '())))

(useReverse '(1 2 3) )


(define mirror0
					;On souhaite renverser totalement la liste
					;Il suffit de detecter si un element de la liste est "simple" ou complexe
					;S'il est "complexe" on lui applique reverse
					;S'il est complexe alors: cdar non null
					;Méthode 2: On aprcours la liste en appliquant reverse à chaque element ensuite on reverse cette liste
  (lambda(L Lr)
    (if (null? L)
	Lr
	(if (list? (car L))
	    (mirror0 (cdr L) (append (list (useReverse (car L))) Lr))
	    (mirror0 (cdr L) (cons (car L) Lr))))))
(define mirror
  (lambda(L)
    (mirror0 L '())))

(mirror LA)


(define carre
					;on parcours simpliement notre liste en les élevant au carré
  (lambda(L)
    (if (null? L)
	()
	(if (list? (car L))
	    (append (list (carre (car L))) (carre (cdr L)))
	    (cons (* (car L) (car L)) (carre (cdr L)))
	    ))))

(carre '(1 (2 6) 3))

(define test
  (lambda(L)
    (if (null? L)
	()
	(cons (* (car L) (car L)) (test (cdr L))))))

(test '(1 2 3))

(define p '(3))


(define nbPositif
  (lambda(L)
    (if (null? L)
	0
	(if (list? (car L))
	    (+ (nbPositif (car L)) (nbPositif (cdr L)))
	    (+ 1 (nbPositif (cdr L)))))))

(nbPositif '(1 (2 (6 7)) 3))

(define membre
  (lambda(x L)
    (if (null? L)
	#f
	(if (list? (car L))
	    (or (membre x (car L)) (membre x (cdr L)))
	    (or (= x (car L)) (membre x (cdr L)))))))

(membre 1 '(5 2 3))

(define epure
					;On utilise une liste secondaire dans laquelle on ajoute les valeurs que l'on a déjà parcouru
					;Si l'on recroise cette valeur on la retire de la liste
					;sinon on la laisse et on l'ajoute à la liste secondaire
  (lambda(L elt)
    (if (null? L)
	()
	(if (membre (car L) elt)
					;si il est membre c'est un doublon
	    (epure (cdr L) elt)
	    (cons (car L) (epure (cdr L) (cons (car L) elt))) ))))

(epure '(1 1 2 3) ())


(define nieme
					;on utilise decremente jusqu'a que le valeur soit de 0 et si la liste n'est pas vide on renvoie l'element
  (lambda(L n)
    (cond ((null? L) (quote "valeur invalide"))
	  ((= n 1) (car L))
	  ((< n 1) (quote "Valeur invalide"))
	  (else (nieme (cdr L) (- n 1))) )))

(nieme '(1 2 3) 3)


(define (mapkar L fn)
  (if (null? L)
      ()
      (cons (fn (car L)) (mapkar (cdr L) fn)) ))


(mapkar '(1 2 3) (lambda (x) (* x x) ))



  
(restart 1)

