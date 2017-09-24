/* Header for read and write utility
 * Copyright (C) bulletcross (Vishal Keshav)

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <blaze/Math.h>
#include <string>

using namespace std;

DynamicMatrix<double> read_csv(string file_name, int nr_rows, int nr_cols){
	DynamicMatrix<double> ret(nr_rows, nr_cols);
	int r=0,c=0;
	string::size_type temp;
	string line, word;
	ifstream file_reader;
	
	file_reader.open(file_name.c_str());
	
	if(!file_reader){
		cout << "Warning: CSV mismatch" << endl;
		return ret;
	}
	while(file_reader){
		string line;
		if(!getline(file_reader, line)){
			break;
		}
		istringstream ss(line);
		while(ss){
			if(!getline(ss, word, ',')){
				break;
			}
			ret(r,c) = stod (word,&temp);
			c++;
		}
		r++;
		c=0;
	}
	return ret;
}