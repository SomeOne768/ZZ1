(define (carre x)
  (* x x))

(carre 2)

(define (quad x)
  ;;retourne x⁴
  (* (carre x) (carre x)))

(quad 2)

(define PI 3.14159)

(define cercle
  (lambda(r)
    ;;retourne une liste contenant la circonference et la surface d'un cercle
    (list (* (* 2 PI) r) (* Pi (carre r)) ) ))

(cercle 1)


(define LA '(1 (2 (6)(7)) (3 (8 12) (9)) (4 (10 (13) (14 (17))) (11 (15 16)) (18)) (5)))


(car la)
(cdr la)

;;sous arbre de racine 2:
(cadr la)
;;de racine 4:
(car (cdddr la))
;;obtenir la feuille 12:
(cadadr (car (cddr la)))
;;sous arbre de racine 10
(cadr (car (cdddr la)))
;;ajouter une feuille à la racine 14
;;1 - obtenir la racine 14:
(define R14 (caddr (cadar (cdddr LA))))

;;2 - On ajoute un element dans le sous arbre (ajout de la feuille 99)
(cons (car R14) (cons 99 (cdr R14)))

;;ajouter une feuille 81, fille de 8 à gauche de 12
;;1-sous arbre de racine 8:
(define R8 (cadr (caddr LA)))

;;2 - ajout de 81:

(cons (car R8) (cons 81 (cdr R8)))




;;3
(define (fact n)
  ;;Prends en entrée un entier naturel
  ;;retourne n!
  (if (= n 0)
      1
      (* n (fact (- n 1))) ))

(fact 2)


;;4
(define (som_int n)
  ;;prends en entrée un entier naturel n
  ;;retourne la somme des n premiers entiers non nuls
  (/ (* n (+ n 1)) 2))

(som_int 5)

(define som_int2
  (lambda(n)
    (if (= n 0)
	0
	(+ n (som_int2 (- n 1))) )))

(som_int2 5)

;;5 Longueur d'une liste
(define (long L)
  (if (null? L)
      0
      (+ 1 (long (cdr L))) ))

(long '(1 2 3) )


;;6 miroir => liste inversée
(define (miroir L)
  ;;L = () => ()
  ;;L = [e | L'] => (L' e) #Comme L' est une liste si on fait un cons on va inserer une liste dans une liste. Il faut donc utiliser append et non cons
  (if (null? L)
      ()
      (let ( (e (car L))
	     (Lprime (cdr L)))
	(append (miroir Lprime) (list e))) ))
;;Version simplifiée:
(define miroir2
  (lambda(L)
    (if (null? L)
	()
	(append (miroir2 (cdr L)) (list (car L))) )))



(miroir '(1 2 3))
(miroir2 '(1 2 3))


;;7
(define carreListe
  ;;Si L vide: => ()
  ;;L = [e | L'] => calculer L' et mettre e² en tête
  (lambda(L)
    (if (null? L)
	()
	(cons (* (car L) (car L)) (carreListe (cdr L)) ) )))


(carreListe '(1 2 3))

;;8
(define nbpos
  ;;L vide => 0
  ;;L = [e | L'] => si e<0 retourner (nbpos L') sinon retourner 1 + (nbpos L')
  (lambda(L)
    (if (null? L)
	0
	(if (< (car L) 0)
	    (nbpos (cdr L))
	    (+ 1 (nbpos (cdr L))) ))))

(nbpos '(0 0 1 -8))

;;9
(define membre
  ;;L vide => message d'erreur
  ;;L = [e | L'] => si e est la valeur recherchée on retourne #t
  ;;                sinon on retourne (membre L')
  (lambda(x L)
    (if (null? L)
	"Message d'erreur"
	(if (equal? x (car L))
	    #t
	    (membre x (cdr L)) ))))

(membre 2 '(1 3 5))
(membre 1 '(1 3 5))


;;10
;;Mthode 1

(define (epure  L)
  ;;L vide => ()
  ;;L = [e | L'] => si e est dans L' retourner (epure L') sinon (cons e (epure L'))
  (if (null? L)
      ()
      (if (equal? "Message d'erreur" (membre (car L) (cdr L)))
	  ;;Flemme de refaire une fonction
	  ;;pas doublon
	  (cons (car L) (epure (cdr L)))
	  ;;est doublon
	  (epure (cdr L)) )))

(epure '(1 1 2 3 4 4 5 2))

;;11
(define (nieme n L)
  ;;n entier naturel
  ;;L vide => Message d'erreur
  ;;L = [e | L']:
  ;;    n = 0 retourner e
  ;;    n > 0 retourner (nieme (- n 1) L')
  (if (null? L)
      "Message d'erreur"
      (if (> n 0)
	  (nieme (- n 1) (cdr L))
	  (car L) )))

(nieme 2 '(0 1 2))
(nieme 3 '(0 1 2))



;;12
(define (inserer n x L)
  ;;Insere x en nieme position dans L (n entier naturel)
  ;;Si n = 0: (cons x L)
  ;;Sinon:
  ;;     -Si L vide on ne fait rien
  ;;     -Sinon L = [e|L'] => inserer x dans a la position n-1 dans L'
  (if (= n 0)
      (cons x L)
      (if (null? L)
	  ()
	  (cons (car L) (inserer (- n 1) x (cdr L))) )))

(inserer 0 82 '(0 1 2 3))
(inserer 2 82 '(0 1 2 3))
(inserer 5 82 '(0 1 2 3))

;;13

(define membre2?
  ;;L vide => message d'erreur
  ;;L = [e | L'] => si e est la valeur recherchée on retourne #t
  ;;                sinon on retourne (membre L')
  (lambda(x L)
    (if (null? L)
	#f
	(if (equal? x (car L))
	    #t
	    (membre2? x (cdr L)) ))))

(membre2? 2 '(1 2))
(membre2? 0 '(1 2))
(define (union L1 L2)
  ;;Il suffit de récupérer les elements de L1 qui ne sont pas dans L2 et les y inserer
  ;;On peut s'aider de insertion puis epurer qui gere les doublons
  ;;L1 vide => retourner L2
  ;;L1 = [e | L'] si e est membre de L2 retourner (union L' L2) sinon inserer e dans L2 et retourner (union L' L2)
  (if (null? L1)
      L2
      (if (membre2? (car L1) L2)
	  (union (cdr L1) L2)
	  (union (cdr L1) (cons (car L1) L2)) )))

(union '(0 1 2 3) '(2 3 4 5))

;;14

(define (inter L1 L2)
  ;;L1 vide => () #Pas/plus d'elts en commun avec L2
  ;;L1 = [e |L'] => Si e € L2 => retourner (cons e (inter (cdr L1) L2))
  ;;                Sinon retourner (inter (cdr L1) L2)
  (if (null? L1)
      ()
      (if (membre2? (car L1) L2)
	  (cons (car L1) (inter (cdr L1) L2))
	  (inter (cdr L1) L2) )))

(inter '(0 1 2) '(2 3 4))
(inter '(0 1 2) '(0 1 2))
(inter '(0 1 2) '(3 4 5))

;;15
(define (niv0 L)
  ;;L vide => ()
  ;;L = [ e | L']: Si e est une liste (append e L') et rappeler la fonction avec L
  ;;               Sinon (cons e L')
  (if (null? L)
      ()
      (if (list? (car L))
	  (niv0 (append (car L) (cdr L)))
	  (cons (car L) (niv0 (cdr L))) )))

(niv0 '(0 1 2))
(niv0 '((0 1) 2 (3 4 (5 6))))


;;16
(define (zip L1 L2)
  ;;retourne la liste des couples L1 L2 en position identique
  ;;/!\ Tailles peuvent être différentes
  (if (or (null? L1) (null? L2))
      ;;Si l'une des listes est vide on s'arrete
      ()
      (cons (list (car L1) (car L2)) (zip (cdr L1) (cdr L2))) ))

(zip '(0 1) '(0 1))
(zip '(0) '(0 1))
(zip '(0 1) '(0))

;;17
(define (prod L1 L2)
  ;;Retourne une liste  L1xL2
  ;;L1 vide => ()
  ;;L1 = [e|L']:
  ;;   -L2 vide: ()
  ;;   -L2 = [e2 |L2']: (cons (e e2) (prod (e) L2')) et inserer cette liste dans la liste (prod L' L2) construite recursivement => utiliser un append (car on insere  une liste de couple dans une autre liste de couple)
  (if (null? L1)
      ()
      (if (null? L2)
	  ()
	  (let ( (e1 (car L1))
		 (e2 (car L2))
		 (L1p (cdr L1))
		 (L2p (cdr L2)))
	    (append (cons (list e1 e2) (prod (list e1) L2p)) (prod L1p L2)) ))))


(prod '(0 1 2) '(0 1 2))
(prod '() '(0 1 2))

;;version plus simple:
;;Parcourir les elements de L1 1 à 1  et faire des listes de couples entre cet elt et ceux de L2

(define (couple e L)
  (if (null? L)
      ();;liste ne contenant aucun couple
      (cons (list e (car L)) (couple e (cdr L)))));; insertion d'un couple dans une liste
(couple 1 '(0 1 2))

(define (prod2 L1 L2)
  (if (null? L1)
      ()
      (cons (couple (car L1) L2) (prod2 (cdr L1) L2)) ))

(prod2 '(0 1 2) '(0 1 2))


;;18
(define (som_list L)
  (if (null? L)
      0
      (+ (car L) (som_list (cdr L))) ))

(som_list '(1 2 3))

;;19
(define (triang n)
  ;;construit une liste (n n-1 n-2 ... 1 ... n-2 n-1 n), n € N*
  ;;On construit à gauche et à droite en même temps en decrémentant n:
  (if (= n 1)
      (list 1)
      (cons n (append (triang (- n 1))  (list n)) )))

(triang 5)


;;Méthode 2:
(define (triang2_1 n)
  (if (= n 1)
      (list 1)
      (cons n (triang2_1 (- n 1))) ))

(triang2_1 5)

(define (triang2_2 n)
  (if (= n 1)
      (list 1)
      (append (triang2_2 (- n 1)) (list n)) ))

(triang2_2 5)


(define (triang2 n)
  (append (triang2_1 n) (triang2_2 n)))

(triang2 5)


;;20
(define (fibo n)
  (if (or (= n 0) (= n 1))
      n
      (+ (fibo (- n 1)) (fibo (- n 2)) ) ))

(fibo 30)
;;A partir d'ici devient trop long
(fibo 50)
(fibo 200)


;;terminal récursif
(define (fibo2 n n1 n2)
  (if (< n 2)
      (if (= n 0)
	  n2
	  n1)
      (if (= n 2)
	  (+ n1 n2)
	  (fibo2 (- n 1) (+ n1 n2) n1) )))

(define (fibo2_utilisation n)
  (fibo2 n 1 0))

(fibo2_utilisation 200)
(fibo2_utilisation 50)
(fibo2_utilisation 30)

;;21 moyenne d'une liste

(define (moyenne L n somme)
  (if (null? L)
      (if (= n 0)
	  0
	  (/ somme n))
      (moyenne (cdr L) (+ n 1) (+ somme (car L))) ))

(moyenne '(1 2 3) 0 0)

;;22
(define (ies L n LI LE LS)
  ;;retourne la liste des nombres inférieurs à n
  (if (null? L)
      (cons LI (cons LE (list LS)));;(list LI LE LS)
      (cond ( (< (car L) n) (ies (cdr L) n (cons (car L) LI) LE LS))
	    ( (= (car L) n) (ies (cdr L) n LI (cons (car L) LE) LS))
	    (else (ies (cdr L) n LI LE (cons (car L) LS))) )))

(ies '(1 2 3) 2 () () ())

;;23
(define (insertion x L)
  ;;insere x dans une liste triée par ordre croissant
  ;;L vide => (x)
  ;;L = [e|L'] => si x<e (cons x L) Sinon (cons e (insertion x (cdr L)))
  (if (null? L)
      (list x)
      (if (< x (car L))
	  (cons x L)
	  (cons (car L) (insertion x (cdr L))) )))

(insertion 5 '(1 2 3))

(define (tri_ins L)
  ;;tri par insertion:
  ;;L vide => ()
  ;;L = [e | L'] => inserer e dans L' triée
  (if (null? L)
      ()
      (insertion (car L) (tri_ins (cdr L))) ))

(tri_ins '(1 2 3))
(tri_ins '(3 2 1))
(tri_ins '(3 1 2))

;;24


(define (min_L L)
  ;;L supposée non vide
  ;;L = [e|L'] : recherché la valeur min de L' puis si e<min L' alors retourner e sinon min L'
  (if (null? (cdr L))
      (car L)
      (let* ( (Lp (cdr L))
	      (min (min_L Lp))
	      )
	(if (< (car L) min)
	    (car L)
	    min))))
      


(min_L '(1 2 3))

(define (supp x L)
  (if (null? L)
      ()
      (if (equal? x (car L))
	  ;;on ne le supprime qu'une seule fois
	  (cdr L)
	  (cons (car L) (supp x (cdr L))) )))

(supp 2 '(1 2 2 3))

(define (tri_sel L)
  ;;Recupere le plus petit de L puis l'insere en debut de liste. Continue ainsi jusqu'à avoir tout trié
  ;;L vide => ()
  ;;L non vide: on insere recupere la valeur min (min_L L)
  ;;on le supprime de la liste:L' = (supp min L)
  ;;on trie le reste de la liste : (tri_sel L')
  ;;on ajoute le min en tete => (cons min (tri_sel L'))
  (if (null? L)
      ()
      (let* ( (min (min_L L))
	      (Lp (supp min L)))
	(cons min (tri_sel Lp))) ))


(tri_sel '(5 8 1 0 6 2 4))


;;25

(define (max_L L)
  ;;supposée non vide
  (if (null? (cdr L))
      (car L)
      (let* ( (maxLp (max_L (cdr L))))
	(if (> (car L) maxLp)
	    (car L)
	    maxLp))))

(max_L '(1 2 3))



(define (tri_bulle L)
  ;; parcours la liste du debut à la fin en comparant successivement un element avec les autres de la liste
  ;;(cherche le max et le met en fin de liste)

  (if (null? L)
      ()
      (let* ( (max (max_L L))
	      (Lp (supp max L)))
	(append (tri_bulle Lp) (list max))) ))

(tri_bulle '(5 2 8 2 4 9 5 6))


;;26

(define (div2L L tailleDiv2)
  ;;L non vide
  ;;tailleDiv2 >0:
  ;;L = [e | e' |L'] => (div2L (cons (cons e' (car L)) L') (- tailleDiv2 1))
  (if (<= tailleDiv2 0)
      (list (car L) (cdr L))
      (if (list? (car L))
	  (div2L (cons (cons (cadr L) (car L)) (cddr L)) (- tailleDiv2 1))
	  (div2L (cons (list (car L)) (cdr L)) (- tailleDiv2 1)) )))


(define (div22L L tailleDiv2)
  (if (<= tailleDiv2 0)
      (cons (car L) (list (cdr L)))
      (let* ( (e (car L));;sous liste en tete
	     (ep (cadr L));;prochain element à entree dans la liste en tete
	     (Lp (cddr L));; reste des elements de la liste initial
	     (Lr (cons (cons ep e) Lp)));;Liste initial reconstruite
	(div22L Lr (- tailleDiv2 1))) ))

(trace div22L)

(div2L '(1 2 ) 1)




  
(define (div2L_init L)
  (div2L L (/ (long L) 2)))
;;Liste contenant la liste L divisée en deux listes

(define (fusion L1 L2)
  ;;principe: on construit une liste avec à chaque fois le plus petit argument en tête
  ;;L1 et L2 étant 2 listes triées
  (if (null? L1)
      L2
      (if (null? L2)
	  L1
	  (if (< (car L1) (car L2))
	      (cons (car L1) (fusion (cdr L1) L2))
	      (cons (car L2) (fusion L1 (cdr L2)))) )))
	      

(define (tri_fus L)
  (if (<= (long L) 1)
      L
      ;;sinon on divise la liste en 2 puis on la tri
      (let ((LD (div2L_init L)))
	(fusion (tri_fus (car LD)) (tri_fus (cadr LD))))))

(trace tri_fus)
(tri_fus '(1 2 0 5 2 1 8))
	
;;27 Algorithme de Hoare (tri rapide)

	  


;;Partie 2



;;Exercice1
;;1°) Ecrire une fonction tous-egaux qui a comme argument une liste L non vide, et qui retourne #t si tous les éléments de L sont égaux et #f sinon.
(define (tous-egaux L)
  (if (null? L)
      #t
      (if (null? (cdr L))
	  #t
	  (and (equal? (car L) (cadr L)) (tous-egaux (cdr L))) )))

(tous-egaux '(1 1 2 1 1))

      
;;a) en utilisant un schéma universel.


;;b) en utilisant un schéma existentiel.






;;Exercice 2
;;1°) Ecrire un schéma de récurrence simple permettant d'évaluer le nième terme d'une suite (un) définie par :
;;un = f ( un-1 , n ) et Un0= B.

(define (Unn f n B)
  (if (= n 0)
      B
      (f (Unn f (- n 1) B) n)))


;;Appliquer ce schéma aux cas de la somme des n premiers entiers non nuls,

(Unn (lambda(Un_1 n)
       (+ n Un_1)) 5 0)

;;de la somme des carrés des n

(Unn (lambda(Un_1 n)
       (+ (* n n) Un_1)) 5 0)


;;de la factorielle

(Unn (lambda(Un_1 n)
       (* n Un_1)) 5 1)



;;de la suite de Fibonacci (en posant Un = ( un , un-1 ), n0 = 0 et U0 = B = '(1 1)).
(Unn (lambda(Un_1 n)
       (if (= n 1)
	   '(1 0)
	   (list (+ (car Un_1) (cadr Un_1)) (car Un_1)))) 3 '(0 0))


;;2°) En déduire un schéma de récurrence double permettant d'évaluer le nième terme d'une suite (un) définie par : un = f (un-1 , un-2 , n ), Un0 = B0,Un0+1= B1.Appliquer à la suite de Fibonacci.


(define (shema_fibo f un_1 un_2 n B)
  (if (= n 0)
      (car B)
      (if (= n 1)
	  (cadr B)
	  (f (shema_fibo f un_2 (- un_2 (- un_1 un_2)) (- n 1) B)))))




;;Exercice 4:

;;Ecrire la fonction PC qui a deux arguments, l'ensemble E et un entier n et qui retourne une liste contenant, sous forme de sous-listes, l'ensemble des n-uplets de E.
;;Exemple :(PC '(0 1) 3) retourne :
;;((0 0 0) (0 0 1) (0 1 0) (0 1 1) (1 0 0) (1 0 1) (1 1 0) (1 1 1)).


(define (trace M)
  (if (null? M)
      0
      (+ (caar M) (trace (map cdr (cdr M))) )))

(define M '( (1 2 3)
	     (4 5 6)
	     (7 8 9) ) )



(define (insertion e L)
  (if (null? L)
      (list e)
      (append (cons e (car L)) (insertion e (cdr L))) ))
 
(define (PC E n)
  ;; inserer chaque element de E dans pc de n-1 jusqu'a obtenir la liste vide (n=0)
  (if (= n 0)
      '(())
      ()))







(define (qqs L P)
  (if (null? L)
      #t
      (if (P (car L))
          (qqs (cdr L) P)
          #f)))

(define l '(0 1 2))


(define (tous-egauxProf L)
  (if (null? L)
      #t
      (qqs (cdr L) (lambda(x)(equal? x (car l))) )))

(tous-egauxProf l)


;;existentiel

(define (exist L P)
  (if (null? L)
      #f
      (if (P (car L))
          #t (exist (cdr L) P) )))



;;Exercie 4: Produits cartésiens

;;Ecrire la fonction PC qui a deux arguments,
;;l'ensemble E et un entier n et qui retourne une liste contenant, sous
;;forme de sous-listes, l'ensemble des n-uplets de E.
;;Exemple :
;;(PC '(0 1) 3) retourne :
;;((0 0 0) (0 0 1) (0 1 0) (0 1 1) (1 0 0) (1 0 1) (1 1 0) (1 1 1)).


;;rendre E x E x... E = E^n
;;On parcourt donc chaque element de E que l'on insere dans PC E n-1

(define (insertion e L)
  ;;L étant une liste de liste
  (map (lambda(sl)
         (cons e sl)) L) )

(define (PC E n)
  ;;On recupere chacune des sous listes de n-1 => (map fn (Pc n-1))
  ;;Pour chacune d'entres elles =>combinaison avec chaque valeur (map fn+insertion E)
  ;;on rassemble ensuite le tout => append
  (map (lambda(sl)
         ;;parcours des sous listes
         (map (lambda(e)
                ;;parcours de E et insertion dans sous liste
                (cons e SL)) E)
         (PC E (- n 1)) )))




(define (PC E n)
  ;;On recupere chacune des sous listes de n-1 => (map fn (Pc n-1))
  ;;Pour chacune d'entres elles =>combinaison avec chaque valeur (map fn+insertion E)
  ;;on rassemble ensuite le tout => append
  (if (= n 0)
      '(())
      (map (lambda(e)
             (insertion e (PC E (- n 1))))
           E) ))


;;V2
(define (PC E n)
  (if (= n 0)
      '(())
      ;;Pour chaque sous liste on insere chaque element de e 1 à 1
      ;;1 => on recupere une sous liste
      ;;2 => on fait toutes les combinaisons possible avec les elements de e
      (append-map (lambda(sl)
             ;;On recupere un element de e
             (map (lambda(e)
                    (cons e sl))
                         E)
             ) (PC E (- n 1))) ))




;;Exercice 5 : Chemins dans un graphe orienté
;;On représente un graphe orienté par une liste G de couples dont le premier élément est un sommet du graphe, et
;;le second la liste des successeurs de ce sommet.
;;Exemple :
;;(let ((G '((D (A C)) (A (D C B)) (C (B)) (B ()))))


;;Ecrire la fonction chemins qui a trois paramètre, dep, but, et G et qui retourne la
;;liste de tous les chemins de G (représentés par des sous listes) partant de dep et
;;arrivant à but.

;;1 - On recupere les voisins de "dep"
;;2 - On regarde si but est voisins si non: on recupere leurs voisin ainsi de suite
;; /!\ Attention: on ne regarde le voisin que s'il est different de "dep"
;;3 - arret si plus de voisins


(define (voisin G sommet)
  ;;sommet existant
  (if (equal? (caar G) sommet)
      (car G)
      (voisin (cdr G) sommet) ))


(define (estVoisin liste_sommet_depart arrivee)
  (exist (cadr liste_sommet_depart) (lambda(s)(equal? s arrivee))) )
  



(define (nb_chemin Graphe dep but)

  (let ( (sl (voisin G sommet)))
    (if (estVoisin sl but)
        ;;recuperer la liste des voisins sans but et dep
        
