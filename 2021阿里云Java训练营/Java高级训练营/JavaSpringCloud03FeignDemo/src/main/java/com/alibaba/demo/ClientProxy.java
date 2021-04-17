package com.alibaba.demo;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.RequestMapping;

@FeignClient(value="OrderService")
public interface ClientProxy {	
	@RequestMapping("/hello")
	public String hi();
}
