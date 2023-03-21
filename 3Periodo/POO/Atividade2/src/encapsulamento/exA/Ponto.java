package encapsulamento.exA;

public class Ponto {
    float x, y;
    
    public Ponto(float x, float y) {
        if(x < 0) {
            this.x = 0;
        } else {
            this.x = x;
        }    
        if(y < 0) {
            this.y = 0;
        } else {
            this.y = x;
        }
    }
    
    public void AlteraX(float x) {
        if(x < 0) {
            this.x= 0;
        } else {
            this.x = x;
        }
    }
    
    public void AlteraY(float y) {
        if(y < 0) {
            this.y = 0;
        } else {
            this.y = x;
        }
    }
    
    public float RetornaPontoX() {
        return this.x;
    }
    
    public float RetornaPontoY() {
        return this.y;
    }
    
    public float Distancia(Ponto p1, Ponto p2) {
        return (float)Math.sqrt(Math.pow((p2.x - p1.x), 2) + Math.pow((p2.y - p1.y), 2));   
    }
}