package main.java.alg.jarray.menu;

import java.util.Scanner;

import main.java.alg.jarray.applicationFunctions.ApplicationFunctions;

public class ShowMenu {

    ApplicationFunctions applicationFunctions = new ApplicationFunctions();
    int[] myArray;

    public void run() {

        System.out.printf(
                "   _                            \n" +
                        "  (_) __ _ _ __ _ __ __ _ _   _ \n" +
                        "  | |/ _` | '__| '__/ _` | | | |\n" +
                        "  | | (_| | |  | | | (_| | |_| |\n" +
                        " _/ |\\__,_|_|  |_|  \\__,_|\\__, |\n" +
                        "|__/                      |___/ \n"
        );

        System.out.println("\n escolha uma opção do menu: ");

        Integer userChoice = getMenuOptions();
        executeFunctionFrom(userChoice);
    }

    private Integer getMenuOptions() {

        System.out.printf(
                "\n> 1 - inicializar um vetor" +
                "\n> 2 - mostrar os valores do vetor criado" +
                "\n"
        );

        Scanner scan = new Scanner(System.in);
        return scan.nextInt();

    }

    private void executeFunctionFrom(Integer userChoice) {

        if(userChoice != null) {
            if(userChoice == 1) myArray = applicationFunctions.initializeNewArray();
            if(userChoice == 2) applicationFunctions.showArray(myArray);
            run();
        }
        else System.out.println("saindo da aplicação");

    }

}
