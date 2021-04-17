package com.alibaba.api;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alibaba.model.Order;

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
	
	@RequestMapping("/hello")
	public String hello() {
		return "Spring Cloud Order Service 2021";
	}
}
