package com.company;

import java.time.LocalDate;
import java.util.Scanner;

public class CardRegisterView {

    private static Scanner userInput = new Scanner(System.in);
    private static String[] address = new String [6];
    private static String[] coupon = new String [2];


    public CardRegisterView() {

    }

    public String getFlyerCardIDFromConsole() {

        System.out.println("Please enter a card ID: ");
        return userInput.nextLine();

    }

    public String getCouponIDFromConsole() {

        System.out.println("Please enter a coupon ID: ");
        return userInput.nextLine();

    }

    public String [] getCardRegisterInfoFromUser() { //come back to this

        int ffp = 0;
        double coupValue = 0;
        String defultCoupId = "000";
        int numberOfYears = 0;
        String [] cardRegInfo = new String [14];
        String cardType = getCardTypeFromConsole();

        if (cardType.equals("PlatinumFrequentFlyer")) {

            cardRegInfo [0] = getFlyerCardIDFromConsole();
            cardRegInfo [1] = getNameFromConsole();
            cardRegInfo [2] = address[0];
            cardRegInfo [3] = address[1];
            cardRegInfo [4] = address[1];
            cardRegInfo [5] = address[2];
            cardRegInfo [6] = address[3];
            cardRegInfo [7] = address[4];
            cardRegInfo [8] = String.valueOf(ffp);
            cardRegInfo [9] = LocalDate.now().toString();

        }

        else {

            cardRegInfo [0] = getFlyerCardIDFromConsole();
            cardRegInfo [1] = getNameFromConsole();
            cardRegInfo [2] = address[0];
            cardRegInfo [3] = address[1];
            cardRegInfo [4] = address[1];
            cardRegInfo [5] = address[2];
            cardRegInfo [6] = address[3];
            cardRegInfo [7] = address[4];
            cardRegInfo [8] = String.valueOf(ffp);
            cardRegInfo [9] = LocalDate.now().toString();
            cardRegInfo [12] = String.valueOf(numberOfYears);

        }

        return cardRegInfo;
    }

    public String getNameFromConsole() {

        System.out.println("Please enter your name: ");
        String name = userInput.nextLine();
        return name;

    }

    public String [] getAddressFromConsole() {


        Address a = null;
        boolean flag = false;
        do {
            System.out.println("Please enter your street number: ");
            address[0] = userInput.nextLine();
            System.out.println("Please enter your street name: ");
            address[1] = userInput.nextLine();
            System.out.println("Please enter your suburb: ");
            address[2] = userInput.nextLine();
            System.out.println("Please enter your city: ");
            address[3] = userInput.nextLine();
            System.out.println("Please enter your state: ");
            address[4] = userInput.nextLine();
            System.out.println("Please enter your postcode : ");
            address[5] = userInput.nextLine();

            try {

                a = new Address(Integer.parseInt(address[0]), address[1], address[2], address[3], address[4], Integer.parseInt(address[5]));

                flag = false;
            }

            catch (Exception ex) {

                flag = true;
                System.out.println("Error, please enter address again");
            }
        }

        while (flag);
        return address;
    }

    public String[] getAddress() {
        return address;
    }

    public String getCardTypeFromConsole() { //Get user to input card type

        System.out.println("Please choose between (P) Platinum Frequent Flyer or (T) Titanium Frequent Flyer: ");
        String cardType = userInput.nextLine();

        if(cardType.equals("P")) {

            cardType = "PlatinumFrequentFlyer";


        }
            else if(cardType.equals("T"))

            {

                cardType = "TitaniumFrequentFlyer";

            }

            else {

                System.out.println("Please enter a valid card type 'P' or 'T' ");
                cardType = userInput.nextLine();
        }

            return cardType;

    }

    public void displayInformationToConsole(String input) {

        System.out.println(input);
    }

}
