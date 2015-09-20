# fingerprintClusterer
This is adapted from OpenRefine's clustering function.

## Usage:

	cd FingerprintKeyer 
	make
	./clusterer PaperKeywords.txt PaperKeywords.clean -c 1,2

<dl>
<dt> -c id_col,string col: </dt>
	<dd>specify column number of original id and the corresponding string column to cluster</dd>

<dt>Output files:</dt>
	<dd> outputfilename : input file with specified columns replaced by cluster name and cluster id</dd>
	<dd> outputfilename+"link" : column1 new_id / column2 original_id</dd>
</dl>