// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int X[], int Y[], int N, char *colors) {
    struct points{
        double dist;
        int color;
    }point[N];
    int greencount=0,redcount=0,totalred=0,totalgreen=0,result = 0;
    double temp;
    // write your code in C99 (gcc 6.2.0)
    int i,a;

    //extract array
    for(i =0; i < N; i++){
        if (i == 0){
            point[i].dist = sqrt(pow(X[i],2)+pow(Y[i],2));
            if (colors[i] == 'R'){
                point[i].color = 1;
                totalred++;
            }
            else{
                point[i].color = 0;
                totalgreen++;
            }
        }
        else{
            a = i;
            temp = sqrt(pow(X[i],2)+pow(Y[i],2));
            while(point[a-1].dist > temp && a > 0){
                point[a].dist = point[a-1].dist;
                point[a].color = point[a-1].color;
                a--;
            }
            point[a].dist = temp;
            if (colors[i] == 'R'){
                point[a].color = 1;
                totalred++;
            }
            else{
                point[a].color = 0;
                totalgreen++;
            }

        }

    }
    //print list of point
    /*
    for(i =0; i < N; i++){
        printf("%d dist is %f color is %d\n",i,point[i].dist, point[i].color);
    }
    */
    
    if(totalred == totalgreen) 
        return N;
    
    for (i = 0; i < N; i++){
        if(point[i].color == 1){
            redcount++;
        }
        else{
            greencount++;
        }
        if((redcount == totalred || greencount ==totalgreen) && i < N-1){
            if(point[i+1].color == 1){
                redcount++;
            }
            else{
                greencount++;
            }
            i++;
            
            break;
        }
        else if (redcount > totalgreen || greencount > totalred){
            break;
        }
    }


    for (;i>=0;i--){
        //printf("greencount is %d\n",greencount);
        //printf("redcount is %d\n",redcount);
        
        if (greencount == redcount){
            if (point[i].dist != point[i+1].dist){
                result = greencount+redcount;
                break;
            }
            else{
                if(point[i].color == 1){
                    redcount--;
                }
                else{
                    greencount--;
                }
            }
        }
        else{
            if(point[i].color == 1){
                    redcount--;
                }
            else{
                    greencount--;
                }
        }
    }
    //printf("result is %d\n",result);
    return result;

}