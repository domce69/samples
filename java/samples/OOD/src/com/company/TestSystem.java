package com.company;

import com.sun.tools.javac.Main;

import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;

public class TestSystem {

    public static void main(String[] args) throws IOException {

        ArrayList<FrequentFlyerCard> flyerCards = new ArrayList<>();
        ArrayList<Coupon> coupons = new ArrayList<>();

        MainSystem ms = new MainSystem();
        CardRegisterView crv = new CardRegisterView();
        CardRegisterSystem crs = new CardRegisterSystem(ms, flyerCards, coupons);

        Coupon coupon1 = new Coupon("001", 10);
        Coupon coupon2 = new Coupon("002", 0);
        coupons.add(coupon1);
        coupons.add(coupon2);

        String [] coupon = new String[2];

        coupon [0] = coupon1.toString();
        coupon [1] = coupon2.toString();

        for (int i = 0; i < coupon.length; i++) {

            System.out.println(coupon[i]);

        }

        Address address1 = new Address(51, "Cabbage Tree Lane", "Fairy Meadow", "Wollongong", "NSW", 2519);
        Address address2 = new Address(41, "Tree Carnage Ave", "Figtree", "Wollongong", "NSW", 2540);

        String [] address = new String[2];
        address [0] = address1.toString();
        address [1] = address2.toString();

        for (int i = 0; i < address.length; i++) {

            System.out.println(address[i]);

        }

        PlatinumFrequentFlyer ff1 = new PlatinumFrequentFlyer("011", "Thomas Andraos", address1, 100000, LocalDate.of(2010,03,20));
        TitaniumFrequentFlyer ff2 = new TitaniumFrequentFlyer("022", "Jared Aragones", address2, 300000,LocalDate.of(2010,03,20), 7);
        PlatinumFrequentFlyer ff3 = new PlatinumFrequentFlyer("033", "Lachlan Abela", address1, 200000, LocalDate.of(2017,03,20));


        flyerCards.add(ff1);
        flyerCards.add(ff2);
        flyerCards.add(ff3);


        String [] frequentFP = new String [2];
        frequentFP [0] = ff1.toString();
        frequentFP [1] = ff2.toString();

        for (int i = 0; i < frequentFP.length; i++) {

            System.out.println(frequentFP[i]);

        }

        AirTicket ticket1 = new AirTicket(991, "Thomas Andras", "Sydney", "Melbourne", 297, 180, 0, TicketType.firstClass, DiscountType.cardDiscount);
        AirTicket ticket2 = new AirTicket(992, "Jared Aragones", "Sydney", "Brisbane", 288, 120, 0, TicketType.businessClass, DiscountType.coupon);

        String [] airTix = new String [2];
        airTix [0] = ticket1.toString();
        airTix [1] = ticket2.toString();

        for (int i = 0; i < airTix.length; i++) {

            System.out.println(airTix[i]);

        }

        System.out.println("");

        crs.displayCardInfo();
        crs.displayCouponInfo();
        crs.createNewCard();
        System.out.println(crs.searchByDiscountID("011"));
        crs.createCouponFromCard();
        System.out.println(crs.getDiscountAmount("033",100,TicketType.firstClass));
        crs.readFile("Card_info.txt");
        crs.writeFile("Card_info.txt");

        for (FrequentFlyerCard f: flyerCards) {

            System.out.println(f.toString());

        }



    }

}
