#include <iostream>
#include <vector>
#include <queue>
#include<fstream>
using namespace std;
 
struct City
{
    vector<int> path;
    int reducedMatrix[21][21];
    int cost;
    int vertex;
    int level;
};
 
 
void printPath( vector<int> TSPpath )
{
	int i;
	
	cout << "TSP¸ô®|¶¶§Ç : " << endl << endl;
	cout << "1";
    for( i = 0; i < TSPpath.size(); i++ ){
        cout << " -> " << TSPpath[i]+1;
    }
    cout << endl;
}
 
struct comp
{
    bool operator()( City* a, City* b ){
        return a->cost > b->cost;
    }
};

 
int main()
{
	int i, j, k, index, cityNum, top, des;
	ifstream file;
    file.open("test5.txt");
    
    file >> cityNum;
	int costMatrix[cityNum][cityNum]; 
	
	index = 0;
    while( !file.eof() ){
    	for( i = 0; i < cityNum; i++ )
    		file >> costMatrix[index][i];
    	index++;
	}
	
	for( i = 0; i < cityNum; i++ ){
		for( j = 0; j < cityNum; j++ ){
			if( costMatrix[i][j] == 0 )
				costMatrix[i][j] = INT_MAX; 
		}
	}
 
 	priority_queue<City*, vector<City*>, comp> pq;
 
    vector<int> path;
 
    City* root = new City;
    root->path = path;
    for( int i = 0; i < cityNum; i++ )
    	for( int j = 0; j < cityNum; j++ )
    		root->reducedMatrix[i][j] = costMatrix[i][j];
    root->reducedMatrix[j][0] = INT_MAX;
    root->level = 0;
    root->vertex = 0;
    
    int cost = 0;
 
    int row[cityNum];
 	for( i = 0; i < cityNum; i++ )
    	row[i] = INT_MAX;
 
    for( i = 0; i < cityNum; i++ ){
        for( j = 0; j < cityNum; j++ ){
            if( root->reducedMatrix[i][j] < row[i] ){
                row[i] = root->reducedMatrix[i][j];
            }
        }
    }
 
    for( i = 0; i < cityNum; i++ ){
        for( j = 0; j < cityNum; j++ ){
            if( root->reducedMatrix[i][j] != INT_MAX && row[i] != INT_MAX ){
                root->reducedMatrix[i][j] -= row[i];
            }
        }
    }
    
    int col[cityNum];
    
    for( i = 0; i < cityNum; i++ )
    	col[i] = INT_MAX;
 
    for( i = 0; i < cityNum; i++ ){
        for( j = 0; j < cityNum; j++ ){
            if ( root->reducedMatrix[i][j] < col[j] ){
                col[j] = root->reducedMatrix[i][j];
            }
        }
    }
 
    for( i = 0; i < cityNum; i++ ){
        for( j = 0; j < cityNum; j++ ){
            if ( root->reducedMatrix[i][j] != INT_MAX && col[j] != INT_MAX ){
                root->reducedMatrix[i][j] -= col[j];
            }
        }
    }
 
    for( i = 0; i < cityNum; i++ ){
    	if( row[i] != INT_MAX )
    		cost += row[i];
    	if( col[i] != INT_MAX )
    		cost += col[i];
    }
    root->cost = cost;
 
    pq.push(root);
  
    while( !pq.empty() ){
        City* min = pq.top();
 
        pq.pop();
 
        top = min->vertex;
 
        if( min->level == cityNum - 1 ){
            min->path.push_back(0);
 
            printPath(min->path);
 
            cout << endl << "cost:" << min->cost << endl;
            return 0;
        }
 
        for( des = 0; des < cityNum; des++ ){
            if( min->reducedMatrix[top][des] != INT_MAX ){
            	
                City* child = new City;
			    child->path = min->path;
			    child->path.push_back( des );
			    
			    for( i = 0; i < cityNum; i++ )
			    	for( j = 0; j < cityNum; j++ )
			    		child->reducedMatrix[i][j] = min->reducedMatrix[i][j];
			 
			    for( k = 0; k < cityNum; k++){
			        child->reducedMatrix[top][k] = INT_MAX;
			        child->reducedMatrix[k][des] = INT_MAX;
			    }
			    child->reducedMatrix[des][0] = INT_MAX;
			    child->level = min->level + 1;
			    child->vertex = des;
			    
                child->cost = min->cost + min->reducedMatrix[top][des];
                cost = 0;
			 	for( i = 0; i < cityNum; i++ )
    				row[i] = INT_MAX;
			 
			    for( i = 0; i < cityNum; i++ ){
			        for( j = 0; j < cityNum; j++ ){
			            if( child->reducedMatrix[i][j] < row[i] ){
			                row[i] = child->reducedMatrix[i][j];
			            }
			        }
			    }
			 
			    for( i = 0; i < cityNum; i++){
			        for( j = 0; j < cityNum; j++){
			            if( child->reducedMatrix[i][j] != INT_MAX && row[i] != INT_MAX ){
			                child->reducedMatrix[i][j] -= row[i];
			            }
			        }
			    }
			    
			    for( i = 0; i < cityNum; i++ )
    				col[i] = INT_MAX;
			 
			    for( i = 0; i < cityNum; i++ ){
			        for( j = 0; j < cityNum; j++ ){
			            if( child->reducedMatrix[i][j] < col[j] ){
			                col[j] = child->reducedMatrix[i][j];
			            }
			        }
			    }
			 
			    for( i = 0; i < cityNum; i++ ){
			        for( j = 0; j < cityNum; j++ ){
			            if( child->reducedMatrix[i][j] != INT_MAX && col[j] != INT_MAX ) {
			                child->reducedMatrix[i][j] -= col[j];
			            }
			        }
			    }
			    
			    for( i = 0; i < cityNum; i++ ){
			    	if( row[i] != INT_MAX )
			    		cost += row[i];
			    	if( col[i] != INT_MAX )
			    		cost += col[i];
			    }
			    child->cost += cost;
			                
 
                pq.push(child);
            }
        }

        delete min;
    }
 	
 	
 
 
}
