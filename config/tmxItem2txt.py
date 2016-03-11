#
# Python assemeber for converting TMX files to a csv file to be read
# In to the game to generate array of obstacles
# input file  : .tmx
# output file : .csv
#
###################################################################

import os;

os.system('rm Itemoutput.csv');

tile = []
tile.append('TMX/level1/tile0.tmx')
tile.append('TMX/level1/tile1.tmx')
tile.append('TMX/level1/tile2.tmx')
tile.append('TMX/level1/tile3.tmx')
tile.append('TMX/level1/tile4.tmx')
tile.append('TMX/level1/tile5.tmx')
tile.append('TMX/level1/tile6.tmx')
tile.append('TMX/level1/tile7.tmx')
tile.append('TMX/level1/tile8.tmx')

array = []

O = open('Itemoutput.csv' ,  'w'); 


numTiles = 9
readLine = 0
read = 0
varString = ""

for i in range(numTiles):
	
	T = open(tile[i], 'r');
	arrayT = []

	for line in T:              
		line = line.rstrip();
	
		if(readLine):
			for char in line:
				if(read):
					if(char=='\"'):
						read = 0
						arrayT.append(varString);
						varString = ""
					else:
						varString += char
				elif(char=='\"'):
					read = 1
				
		if(line==' <objectgroup name="Items">'):
			readLine = 1
		if(line==' </objectgroup>'):
			readLine = 0
	
	array.append(arrayT)
	T.close()
	
	
numObs = []

O.write('%d\n' % numTiles);


for k in range(len(tile)):
	numObs.append(len(array[k]))
	x = numObs[k]/4
	O.write('%d ' % x);
	
O.write('\n')
O.write('3\n')


for k in range(len(tile)):
	for n in range(numObs[k]):
		if(n%4==0):
			n+=1
		elif(n%4==1):
			O.write(array[k][n]);
			O.write(' ');
			n +=1
		elif(n%4==2):
			O.write(array[k][n]);
			O.write(' ');
			n +=1
		elif(n%4==3):
			O.write(str(1054-int(array[k][n])));
			O.write(' ');
			n +=1
		if(n%4==0 and n!=0):
			O.write('\n');
	
	
O.close();
