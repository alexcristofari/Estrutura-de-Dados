import java.util.ArrayList;
import java.util.Random;

public class ListaAleatoria {
    public static void main(String[] args) {
        int n = 10; 

        ArrayList<Integer> lista = new ArrayList<>();
        
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            lista.add(rand.nextInt(100)); 
        }
        
        System.out.println("Lista original: " + lista);
        
        System.out.println("Número de elementos na lista: " + lista.size());
        
        lista.removeIf(número -> número % 2 == 0);
        
        System.out.println("Lista após remover os números pares: " + lista);
        
        System.out.println("Número de elementos na lista após remoção dos pares: " + lista.size());
    }
}
