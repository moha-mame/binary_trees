/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to lowest common ancestor node or NULL
 */
 binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
 		const binary_tree_t *second)
 {
 	binary_tree_t *mom, *pop;

 	if (!first || !second)
 		return (NULL);
 	if (first == second)
 		return ((binary_tree_t *)first);

 	mom = first->parent, pop = second->parent;
 	if (first == pop || !mom || (!mom->parent && pop))
 		return (binary_trees_ancestor(first, pop));
 	else if (mom == second || !pop || (!pop->parent && mom))
 		return (binary_trees_ancestor(mom, second));
 	return (binary_trees_ancestor(mom, pop));
 }
