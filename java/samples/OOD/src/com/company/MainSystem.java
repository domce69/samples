package com.company;

public class MainSystem {

    private CardRegisterSystem crs;

    public MainSystem() {

        this.crs = new CardRegisterSystem(this, crs.flyerCards, crs.coupons);
    }

    public void generateCoupon() {

        crs.createCouponFromCard();

    }

    public void createCard() {

        crs.createNewCard();

    }

    protected DiscountType getDiscountType(String discountId){

       return crs.getDiscountType(discountId);

    }

    protected double getDiscountAmount(String discountId, double price, TicketType ticketType) {

        return crs.getDiscountAmount(discountId, price, ticketType);

    }



}
