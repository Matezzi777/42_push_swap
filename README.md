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
❗	Les arguments peuvent être passé comme une suite d'arguments ou comme une seule string avec les arguments séparés par des espaces :
❗		Exemple : `./push_swap "1" "2" "3"` ou `./push_swap "1 2 3"` sont valides. Mais `./push_swap "1" "2 3"` n'est pas valide.

3. Implémenter l'algorithme de tri (Turk Algorithm) ❌
Pour chaque mouvement :
- Calculer le *coût* pour faire remonter chaque nodes.
- Identifier la cible de chaque node (la node à côté de laquelle elle doit être push)
- Faire remonter la node et sa cible dont le total des *coûts* est le plus faible.
Une fois toute la stack triée à l'envers en b (sauf 2 nodes), tout repush vers stack a.
