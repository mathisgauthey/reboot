package conditionalhello;

/**
 * Ce programme affiche
 * - un message Hello personnalisé si un argument a été envoyé lors de
 * l'exécution du programme
 * - le message traditionnel "Hello World!" si ce n'est pas le cas
 *
 * @author L'équipe Éducation d'OpenClassrooms
 */

public class conditionalworld {

    /**
     * Le programme commence ici
     *
     * @param args arguments envoyé avec la ligne de commande
     */

    public static void main(String[] args) {

        if (args.length == 1) {
            sayHelloTo(args[0]);
        } else {
            sayHelloTo("world");
        }

    }

    /**
     * affiche le message hello au destinataire fourni
     *
     * @param recipient
     */

    private static void sayHelloTo(String recipient) {
        System.out.println("Hello " + recipient + "!");
    }

}