# fingerprintClusterer
This is adapted from OpenRefine's clustering function.

## Usage:

	cd FingerprintKeyer 
	make
	./clusterer PaperKeywords.txt PaperKeywords.clean -c 1,2

* -c id_col,string col:
	specify column number of original id and the corresponding string column to cluster

* There will be two output files:
	outputfilename : input file with specified columns replaced by cluster name and cluster id
	outputfilename+"link" : column1 new_id / column2 original_id
