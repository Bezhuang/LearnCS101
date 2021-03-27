package com.alibaba.api;

import com.alibaba.model.Order;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class OrderController {

    @RequestMapping("/getOrder")
    public Order getOrder()
    {
        Order order = new Order();
        order.setId(1);
        order.setTitle("Iphone 18 pro Max");
        return order;
    }
}
