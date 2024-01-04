food(burger). % burger is a food
food(sandwich). % sandwich is a food
food(pizza). % pizza is a food
lunch(sandwich). % sandwich is a lunch
dinner(pizza). % pizza is a dinner

meal(X) :- food(X). % Every food is a meal OR Anything is a meal if it is a food

