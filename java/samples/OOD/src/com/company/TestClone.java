package com.company;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;

public class TestClone {

    public static void main(String[] args) throws CloneNotSupportedException {

        ArrayList<FrequentFlyerCard> flyerCards = new ArrayList<>();
        ArrayList<Coupon> coupons = new ArrayList<>();

        ArrayList<Coupon> cloneCoupons;
        ArrayList<FrequentFlyerCard> cloneCards;

        //Coupons
        Coupon coupon1 = new Coupon("001", 10);
        Coupon coupon2 = new Coupon("002", 0);
        coupons.add(coupon2);
        coupons.add(coupon1);


        //Address'
        Address address1 = new Address(51, "Cabbage Tree Lane", "Fairy Meadow", "Wollongong", "NSW", 2519);
        Address address2 = new Address(41, "Tree Carnage Ave", "Figtree", "Wollongong", "NSW", 2540);

        //FlyerCards
        PlatinumFrequentFlyer ff1 = new PlatinumFrequentFlyer("011", "Thomas Andraos", address1, 100000, LocalDate.of(2010,03,20));
        TitaniumFrequentFlyer ff2 = new TitaniumFrequentFlyer("022", "Jared Aragones", address2, 300000,LocalDate.of(2010,03,20), 7);
        PlatinumFrequentFlyer ff3 = new PlatinumFrequentFlyer("033", "Lachlan Abela", address1, 200000, LocalDate.of(2017,03,20));

        flyerCards.add(ff3);
        flyerCards.add(ff1);
        flyerCards.add(ff2);



        for (FrequentFlyerCard f: flyerCards) {

            System.out.print("Unsorted Flyer Cards");
            System.out.println(f);

        }

        System.out.println("");

        cloneCards = deepCloneFlyerCards(flyerCards);

        for (FrequentFlyerCard f: cloneCards) {

            System.out.print("Sorted Clone Cards");
            System.out.println(f.toString());

        }


        System.out.println("");

        for (Coupon c: coupons) {

            System.out.print("Unsorted Coupon: ");
            System.out.println(c);

        }

        System.out.println("");

        cloneCoupons = deepCloneCoupons(coupons);

        for (Coupon c: cloneCoupons) {

            System.out.print("Sorted Clone Coupon: ");
            System.out.println(c);

        }





    }


    public static ArrayList deepCloneFlyerCards(ArrayList<FrequentFlyerCard> f) throws CloneNotSupportedException {

        ArrayList<FrequentFlyerCard> cloneCards = new ArrayList<>();
        for (FrequentFlyerCard cards: f) {

            if (cards.getClass() == TitaniumFrequentFlyer.class) {

                TitaniumFrequentFlyer newTFF = (TitaniumFrequentFlyer) cards.clone();
                cloneCards.add(newTFF);

            }

            else if (cards.getClass() == PlatinumFrequentFlyer.class) {

                PlatinumFrequentFlyer newTFF = (PlatinumFrequentFlyer) cards.clone();
                cloneCards.add(newTFF);

            }
        }

        Collections.sort(cloneCards);
        cloneCards.stream().map(clone -> clone.id);
        return cloneCards;
    }

    public static ArrayList deepCloneCoupons(ArrayList<Coupon> c) throws CloneNotSupportedException {

        ArrayList<Coupon> cloneCoupons = new ArrayList<>();
        for (Coupon coups: c) {

            Coupon newCoup = coups.clone();
            cloneCoupons.add(newCoup);

        }

        Collections.sort(cloneCoupons);
        cloneCoupons.stream().map(clone -> clone.id);
        return cloneCoupons;
    }



}

