package com.alibaba.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TestController {
	@Autowired
	private ClientProxy clientproxy;
	@RequestMapping("/hi")
	public String hi() {
		return clientproxy.hi();
	}
}
