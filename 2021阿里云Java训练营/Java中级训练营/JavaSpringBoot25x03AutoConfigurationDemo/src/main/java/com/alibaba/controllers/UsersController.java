package com.alibaba.controllers;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import com.alibaba.models.Users;

@RequestMapping("/Users")
@Controller
public class UsersController {

	@GetMapping
	public String hello() {
		return "Hello Java Spring Boot";
	}

 
	@RequestMapping("/getAll")
	@ResponseBody
	public List<Users> getAllUsers() {
		
		return null;
	}

	@RequestMapping("/getById/{id}")
	@ResponseBody
	public Users getUserById(@PathVariable int id) {
		System.out.println(id);
		return null;
	}
}
