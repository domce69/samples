package thomasandraos6280341;
import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files


public class Main {

    String[] wrds; //declaring attributes
    int[] counts;
    Boolean isUnique = true;
    char[] alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //creating character array of alphabet
    String compWord = "";

    public Main(String[] wrds, int[] counts){ //constructor

        this.wrds = wrds;
        this.counts = counts;
    }


    public int readTxtFile(String txtFile) {

        int totalWords = 0; //creating variables
        int j = 0;

        try { //reading text file in word by word
            File filePath = new File(txtFile);
            Scanner inData = new Scanner(filePath);
            while (inData.hasNext()) {
                String w = inData.next(); //setting w to the word from text file

                char arr[] = w.toCharArray(); //setting all characters to lower case
                for (char c : arr) {
                    c = Character.toLowerCase(c);

                    for (char d : alphabet) { //checking if character is in the alphabet array and if it is adding it to the string to complete word without punctuation

                        if (c == d) {
                            compWord += c;
                        }
                    }
                }

                for(int i = 0; i < j; i++){

                    if(compWord.equals(wrds[i])){ //checking if the word exists in the array, if so increasing the count
                        counts[i]+=1;
                        compWord = "";
                        isUnique = false;
                        totalWords++; //total word count
                    }
                }


                if(isUnique && !compWord.equals("")){ //if the word isnt already in the array it adds the word and a count of 1
                    wrds[j] = compWord;
                    counts[j] = 1;
                    compWord = "";
                    totalWords++; //total word count
                    j++;
                }
                isUnique = true;

            }
        } catch (FileNotFoundException e) { //catch for file stream
            e.printStackTrace();
        }

        System.out.println("Total word count: " + totalWords); //printing word totals
        System.out.println("Total unique word count: " + j );

        return j; //returns the total unique words (the amount of entries in the array)
    }

    void sortDesending(int n){
        for (int i = 0; i < n; i++) { //for loop from 0 to n ++
            for(int j = i + 1; j < n; j++){  //for loop i + 1 to n ++
                if(counts[j] > counts[i]){ //if the count j is higher then count i swap positions in array for count and word to sort by decreasing count
                    String word = wrds[j];
                    int numb = counts[j];

                    wrds[j] = wrds[i];
                    wrds[i] = word;

                    counts[j] = counts[i];
                    counts[i] = numb;
                }
            }
        }
    }

    void sortAlphabet(int n){
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j++) {
                if (counts[i] == counts[j]) { //if counts are the same compare the two words and swap positions in the array based on alphabetical order
                    if (wrds[i].compareTo(wrds[j])>0) {
                        String word = wrds[i];
                        wrds[i] = wrds[j];
                        wrds[j] = word;
                    }
                }
            }
        }
    }



    public void printFirstFifteen(){ //printing the first 15 words and counts in the array from the top
        System.out.println("\nFirst Fifteen");
        for(int i = 0; i < 15; i ++){
            System.out.println(wrds[i] + " " + counts[i]);
        }
    }

    public void printLastFifteen(int n){ //printing the last 15 words and counts in the array from j-15
        System.out.println("\nLast Fifteen");
        for(int i = n - 1; i > n - 16; i--){
            System.out.println(wrds[i] + " " + counts[i]);
        }
    }

    public static void main(String[] args) {

        String txtfile;
        int max = 50000;
        String[] wrds = new String[max];
        int[] counts = new int[max];

        Scanner userIn = new Scanner(System.in); //scanner taking in users file path
        System.out.println("Enter file path of text file including .txt extention: ");
        txtfile = userIn.nextLine();

        Main mn = new Main(wrds, counts); //creating new object and running methods
        int n = mn.readTxtFile(txtfile);
        mn.sortDesending(n);
        mn.sortAlphabet(n);
        mn.printFirstFifteen();
        mn.printLastFifteen(n);

    }
}
