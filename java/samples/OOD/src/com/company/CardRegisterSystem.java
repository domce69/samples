package com.company;

import com.sun.tools.javac.Main;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class CardRegisterSystem implements Cloneable, Comparable<CardRegisterSystem>{

    private static CardRegisterView view = new CardRegisterView();
    static ArrayList<FrequentFlyerCard> flyerCards;
    static ArrayList <Coupon> coupons;
    private MainSystem ms;

    public CardRegisterSystem(MainSystem ms, ArrayList flyerCards, ArrayList coupons) {
        this.ms = ms;
        this.flyerCards = flyerCards;
        this.coupons = coupons;
    }

    public void displayCardInfo() {

        displayCardInfo(view.getFlyerCardIDFromConsole());
    }

    public void displayCardInfo(String cardId) {

        for (FrequentFlyerCard f: flyerCards) {

            if (cardId.equals(f.id)) {

                System.out.println(f.toString());

            }

        }

    }

    public void displayCouponInfo() {

        displayCouponInfo(view.getCouponIDFromConsole());

    }

    public void displayCouponInfo(String couponId) {

        for (Coupon c: coupons) {

            if (couponId.equals(c.id)) {

                System.out.println(c.toString());

            }

        }

    }

    //------------------------------------------------------------//

    public void createNewCard() {

        registerCard(view.getCardRegisterInfoFromUser());

    }


    protected void registerCard(String [] userInfo) {

        String [] address = view.getAddressFromConsole();

        int count = 0;
        for (int i = 0; i < userInfo.length; i ++)
            if (userInfo[i] != null)
                count ++;

        if (count == 10) {

            Address addr = Address.getInstanceFromStringArray(address);
            PlatinumFrequentFlyer newPlat = new PlatinumFrequentFlyer(userInfo[0], userInfo[1], addr, Integer.valueOf(userInfo[8]), LocalDate.parse(userInfo[9]));
            flyerCards.add(newPlat);
        }

        else if (count == 11){

            Address addr = Address.getInstanceFromStringArray(address);
            TitaniumFrequentFlyer newTitanium = new TitaniumFrequentFlyer(userInfo[0], userInfo[1], addr, Integer.valueOf(userInfo[8]), LocalDate.parse(userInfo[9]), Integer.valueOf(userInfo[12]));
            flyerCards.add(newTitanium);

        }

        System.out.println("Card Confirmation - ID: " + userInfo[0] + " Name: " + userInfo[1] + " Date of Activation: " + userInfo[9]);

    }

    //------------------------------------------------------------//

    public void createCouponFromCard() {

        genCoupon(view.getFlyerCardIDFromConsole());

    }


    protected Coupon genCoupon (String id) {

        Coupon genCoup =  new Coupon(id, 0);
        System.out.println(genCoup);
        return genCoup;

    }

    //------------------------------------------------------------//

    protected DiscountType getDiscountType(String discountId) {

        DiscountType discType = null;

        for (FrequentFlyerCard f: flyerCards) {

            for (Coupon c : coupons) {

                if (discountId.equals(c.id)) {

                    discType = DiscountType.coupon;

                } else if (discountId.equals(f.id)) {

                    discType = DiscountType.cardDiscount;

                } else {

                    System.out.println("None");

                }
            }
        }

        return discType;

    }

    protected double getDiscountAmount(String discountId, double price, TicketType ticketType) {

        double discAmount = 0;
        for (FrequentFlyerCard f: flyerCards) {

                if(discountId.equals(f.id)) {

                    if (f.getClass() == TitaniumFrequentFlyer.class) {

                        if (ticketType == TicketType.economyClass) {

                            discAmount = price * 0.01;

                        } else {

                            discAmount = price * 0.10;
                        }

                    }

                     if (f.getClass() != TitaniumFrequentFlyer.class) {


                        if (ticketType == TicketType.economyClass) {

                            discAmount = price * 0.01;

                        } else {

                            discAmount = price * 0.05;
                        }

                    }

                }
            }

        for (Coupon c : coupons) {

            if (discountId.equals(c.id)) {

                discAmount = c.getValue();

            }

        }

        return discAmount;
    }

    public String searchByDiscountID(String discountId) { //come back to this ELSE = 0 NOT WORKING

        String discountObject = "0";

        for (FrequentFlyerCard f : flyerCards) {

            if (discountId.equals(f.id)) {

                discountObject = f.toString();

            }


        }

        for (Coupon c : coupons) {

            if (discountId.equals(c.id)) {

                discountObject = c.toString();

            }

        }


        return discountObject;
    }

    public void addFlyerCard(FrequentFlyerCard f) {

        flyerCards.add(f);

    }

    @Override
    public int compareTo(CardRegisterSystem o) {
        return 0;
    }

    public void readFile (String fileName) {


        Scanner in=null;
        boolean err0 =false;
        try {
            in= new Scanner(Paths.get(fileName));
        } catch (IOException ex) {
            err0 =true;
        }
        if (!err0)
        {
            while(in.hasNext())
            {
                String scard = in.nextLine();
                String[] input = scard.split(",");
                FrequentFlyerCard temp = null;
                try {

                    if(input.length==10)
                    {
                        Address addr = new Address(Integer.parseInt(input[2]),input[3],input[4],input[5],input[6], Integer.parseInt(input[7]));
                        temp = new PlatinumFrequentFlyer(input[0], input[1], addr, Integer.parseInt(input[8]), LocalDate.parse(input[9]));
                        addFlyerCard(temp);
                    }

                    else if (input.length==11)
                    {
                        Address addr = new Address(Integer.parseInt(input[2]),input[3],input[4],input[5],input[6],Integer.parseInt(input[7]));
                        temp = new TitaniumFrequentFlyer(input[0], input[1], addr, Integer.parseInt(input[8]), LocalDate.parse(input[9]), Double.parseDouble(input[10]));
                        addFlyerCard(temp);
                    }

                }

                catch(NoSuchElementException ex)

                {
                    System.out.println("File improperly formed. Terminating.");
                }

            }

            in.close();

        }

    }

    public void writeFile(String fileName) {

        File f1= new File(Paths.get(fileName).toUri());
        Formatter out=null;
        boolean err =false;

        for (FrequentFlyerCard flyerCard: flyerCards)

        {
            flyerCard.setFrequentFlyerPoints(61626364);

        }

        try {

                    out = new Formatter(f1);
                    } catch (FileNotFoundException ex) {
                    err= true;
                    }

            if (!err) {


                for(FrequentFlyerCard flyerCard : flyerCards)
                    {
                    out.format("%s%n", flyerCard.getDataToSaveToTextFile());
            }

                    out.close();
                  }

            }
        }