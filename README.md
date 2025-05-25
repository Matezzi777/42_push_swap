1. Créer les opérations : ✅
- ✅ sa
- ✅ sb
- ✅ ss
- ✅ pa
- ✅ pb
- ✅ ra
- ✅ rb
- ✅ rr
- ✅ rra
- ✅ rrb
- ✅ rrr

2. Parsing : ✅
- ✅ Si aucun argument : -> Rend le prompt.
- ✅ Sinon, récupérer chaque argument passé, renvoyer une erreur si :
	✅ - Un argument n'est pas un entier (positif ou négatif).
	✅ - Un argument ne rentre pas dans un int.
	✅- Deux arguments sont identiques.
❗	Les arguments peuvent être passé comme une suite d'arguments ou comme une seule string avec les arguments séparés par des espaces :	❗
❗		Exemple : `./push_swap "1" "2" "3"` ou `./push_swap "1 2 3"` sont valides. Mais `./push_swap "1" "2 3"` n'est pas valide.		❗

3. Implémenter l'algorithme de tri (Turk Algorithm) ❌
	1. ✅ Push 2 éléments dans la stack b.
	2. ❌ Push les éléments dans l'ordre décroissant dans la stack b avec les moins de coûts à chaque fois jusqu'à plus que 3 éléments dans a.
		1. ❌ Trouver la "cible" de chaque élément (l'élément de b qui doit être sur le dessus au moment de push).
			= l'élément avec la valeur inférieure la plus proche.
			ou le plus grand élément de b si l'élément va devenir le nouveau plus petit de b après push.
		2. ❌ Calculer le coût pour mettre à la bonne place de chaque élément.
		(coût pour mettre au top + coût pour mettre cible au top (Si même direction, coût du plus cher des deux))
		3. ❌ Effectuer les opérations pour envoyer l'élément le moins cher à sa place dans b.
	3. ❌ Trier les 3 éléments restants de a.
	4. ❌ Repush tous les éléments de b vers a en les mettant à la bonne place.
	5. ❌ Ramener l'élément le plus petit en haut de la pile. TADAAAAA la stack est triée.
