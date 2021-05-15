package com.alibaba.demo;

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
		order.setPrice(8888);
		order.setAddress("杭州阿里巴巴总部");
		return order;
	}
}
