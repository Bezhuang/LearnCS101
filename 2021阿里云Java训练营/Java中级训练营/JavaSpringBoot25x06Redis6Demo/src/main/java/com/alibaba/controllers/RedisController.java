package com.alibaba.controllers;

import java.io.Serializable;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.alibaba.entity.Users;
@RequestMapping("/Redis")
@Controller
public class RedisController {

	   @Autowired
	    private RedisTemplate<String, String> strRedisTemplate;
	    @Autowired
	    private RedisTemplate<String, Serializable> serializableRedisTemplate;
	    

	@GetMapping
	public String hello() {
		return "Hello Java Spring Data Redis";
	}

	@RequestMapping("/add")
	@ResponseBody
	public int addUsers() {
		for (int i = 0; i < 100; i++) {
			Users entity = new Users();
			entity.setId(i);
			entity.setName("Java Spring Boot 2.5x实战Redis：" + i);
			entity.setPassword("password12345678" + i);
			 serializableRedisTemplate.opsForValue().set("redis"+ i, entity);      
		}
		return 100;
	}

	@RequestMapping("/get/{id}")
	@ResponseBody
	public Users getUserById(@PathVariable int id) {
		System.out.println(id);
		Users user = (Users) serializableRedisTemplate.opsForValue().get("redis"+id);
		return user;
	}
}
