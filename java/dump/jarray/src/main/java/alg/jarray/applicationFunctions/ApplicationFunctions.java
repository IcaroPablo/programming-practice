package main.java.alg.jarray.applicationFunctions;

import java.util.Scanner;

public class ApplicationFunctions {

    Scanner scan = new Scanner(System.in);
    public int[] initializeNewArray() {

        //limpar tela
        int userResponse = getUserResponse();
        return getCreationMethodFromResponse(userResponse);

    }

    private Integer getUserResponse() {

        System.out.println("> 1 - preencher vetor automaticamente");
        System.out.println("> 2 - preencher vetor manualmente");
        System.out.println("> 3 - carregar vetor a partir de um arquivo");

        return scan.nextInt();

    }

    private int[] getCreationMethodFromResponse(int userResponse) {

        if(userResponse == 1) return generateAutomatically();
        else if(userResponse == 2) return generateManually();
        else if(userResponse == 3) return loadFromFile();
        else return initializeNewArray();

    }

    private int[] generateAutomatically() {

        System.out.println("digite o tamanho do seu vetor: ");
        int arraySize = scan.nextInt();

        int[] newArray =  new int[arraySize];

        for(int i = 0; i < arraySize; i++) newArray[i] = 1; // valores aleatorios

        System.out.println("Vetor criado: ");
        showArray(newArray);
        return newArray;

    }

    private int[] generateManually() {

        System.out.println("digite o tamanho do seu vetor: ");
        int arraySize = scan.nextInt();

        int[] newArray =  new int[arraySize];

        for(int i = 0; i < arraySize; i++) newArray[i] = scan.nextInt(); // valores aleatorios

        return newArray;

    }

    private int[] loadFromFile() {

        System.out.println("digite o caminho completo para o seu arquivo: ");
        String arraySize = scan.nextLine();

        System.out.println("todo");

        return new int[] {1};

    }

    public void showArray(int[] array) {

        if(array == null) {
            System.out.println("vetor não válido");
            return;
        }

        String arrayToString = "[";

        for(int i = 0; i < array.length; i++) arrayToString += String.valueOf(array[i]) + ", ";

        arrayToString += "\b\b]";

        System.out.println(arrayToString);

    }

}
