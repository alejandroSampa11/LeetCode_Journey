class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int previous = 0;
        int maximo = 0;
        char letra = CHAR_MIN;
        for(int i = 0;i<keysPressed.size();i++){
            if((releaseTimes[i]-previous) > maximo){
                maximo = releaseTimes[i]-previous;
                letra = keysPressed[i];
            }
            if((releaseTimes[i]-previous) == maximo){
                if(keysPressed[i]>letra){
                    letra = keysPressed[i];
                    maximo = releaseTimes[i]-previous;
                }
            }
            previous = releaseTimes[i];
        }
        return letra;
        
    }
};