import java.util.*;
import java.util.stream.Collectors;

public class Ordenacao {

    public static void main(String[] args) {

        List<String> palavras = new ArrayList<>();

        palavras.add("pikachu");
        palavras.add("shar");
        palavras.add("shari");
        palavras.add("Charmander");
        palavras.add("charmeleon");
        palavras.add("Sharizard");
        palavras.add("pidgey");

        System.out.println(palavras);

        Map<Character, Integer> alfabeto = new HashMap<>();

        alfabeto.put('a', 1);
        alfabeto.put('b', 2);
        alfabeto.put('c', 3);
        alfabeto.put('d', 4);
        alfabeto.put('e', 5);
        alfabeto.put('f', 6);
        alfabeto.put('g', 7);
        alfabeto.put('h', 8);
        alfabeto.put('i', 9);
        alfabeto.put('j', 10);
        alfabeto.put('k', 11);
        alfabeto.put('l', 12);
        alfabeto.put('m', 13);
        alfabeto.put('n', 14);
        alfabeto.put('o', 15);
        alfabeto.put('p', 16);
        alfabeto.put('q', 17);
        alfabeto.put('r', 18);
        alfabeto.put('s', 19);
        alfabeto.put('t', 20);
        alfabeto.put('u', 21);
        alfabeto.put('v', 22);
        alfabeto.put('w', 23);
        alfabeto.put('x', 24);
        alfabeto.put('y', 25);
        alfabeto.put('z', 26);

        Integer[][] codigos = new Integer[palavras.size()][];

        int cont2 = 0;
        for(String p : palavras) {

            Integer[] codigo = new Integer[p.length()];
            int cont = 0;

            //transformar palavra em lista de letras
            List<Character> chars = p.toLowerCase(Locale.ROOT).chars().mapToObj(e -> (char)e).collect(Collectors.toList());

            //percorrer as letras substituindo elas por numeros (criando um código)
            for(Character c : chars) codigo[cont++] = alfabeto.get(c);

            //inserir o códig na lista de codigos
            codigos[cont2++] = codigo;

        }

        //organizar: algoritmo bubble sort
        for(int i = 0; i < codigos.length - 1; i++) {
            for(int j = 0; j < codigos.length - 1 - i; j++) {
                if(ifgts(codigos[j], codigos[j + 1])) {
                    Integer[] aux = codigos[j];
                    codigos[j] = codigos[j + 1];
                    codigos[j + 1] = aux;
                }
            }
        }

        //converter de volta para palavras
        palavras.clear();

        for(int c = 0; c < codigos.length; c++) {

            String palavra = "";

            for(Integer n = 0; n < codigos[c].length; n++) {
                for(char k : alfabeto.keySet()) {
                    if(codigos[c][n] == alfabeto.get(k)) {
                        palavra += k;
                        break;
                    }
                }
            }

            palavras.add(palavra);

        }

        System.out.println(palavras);

    }

    // is first greater than second ?
    public static Boolean ifgts(Integer[] first, Integer[] second) {

        try {
            for (int i = 0; i < first.length - 1; i++) {
                if(first[i] > second[i]) return true;
                else if(first[i] < second[i]) return false;
            }
        } catch(Exception e) {
            return true;
        }
        return false;

    }

}
