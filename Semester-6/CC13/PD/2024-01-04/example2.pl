studies(charlie, csc135). % charlie studies csc135
studies(olivia, csc135). % olivia studies csc135
studies(jack, csc131). % jack studies csc131
studies(arthur, csc134). % arthur studies csc134

teaches(kirke, csc135). % kirke teaches csc135
teaches(collins, csc131). % collins teaches csc131
teaches(collins, csc171). % collins teaches csc171
teaches(juniper, csc134). % juniper teaches csc134

professor(X,Y) :- teaches(X,C), studies(Y,C). % X is a professor of Y if X teaches C and Y studies C
