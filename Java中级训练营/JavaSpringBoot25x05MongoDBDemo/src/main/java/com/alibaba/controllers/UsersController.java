package com.alibaba.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.alibaba.models.Users;
import com.alibaba.repository.UsersRepository;

@RequestMapping("/Users")
@Controller
public class UsersController {

	@Autowired
	private UsersRepository usersRepository;
	 
	@GetMapping
	public String hello() {
		return "Hello Java Spring Boot 25x";
	}
	
	@RequestMapping("/addUsers")
	@ResponseBody
	public int addUsers() {
		usersRepository.deleteAll();
		for (int i = 0; i < 100000; i++) {
			Users entity = new Users();
			entity.setId(i);
			entity.setName("Java Spring Boot 2.5x实战："+i);
			entity.setPassword("password"+i);
			usersRepository.save(entity);
		}
		//List<Users> listUsers = usersRepository.findAll();
		//System.out.println(listUsers.size());
		return 100000;
	}
	
	@RequestMapping("/getAll")
	@ResponseBody
	public List<Users> getAllUsers() {
		List<Users> listUsers = usersRepository.findAll();
		System.out.println(listUsers.size());
		return listUsers;
	}

	@RequestMapping("/getById/{id}")
	@ResponseBody
	public Users getUserById(@PathVariable int id) {
		System.out.println(id);
		Users user = usersRepository.getUserById(id);
		return user;
	}
}
