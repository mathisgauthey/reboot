package hello; // Nom du dossier

public class helloworld { // Nom du fichier
    public static void main(String[] args) {
        System.out.println("Hello World!");

        String exemple = "hello";
        System.out.println(exemple);
        exemple = exemple.toUpperCase();
        System.out.println(exemple);
        exemple = exemple.replace("HELL", "YEAH");
        System.out.println(exemple);
    }
}
