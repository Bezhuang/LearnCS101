package com.alibaba.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;

import com.alibaba.models.Users;
import com.alibaba.repository.UsersRepository;

@RequestMapping("/Home")
@Controller
public class HomeController {
	@Autowired
	private UsersRepository usersRepository;
	
	@RequestMapping("/getAllUsers")
	@ResponseBody
	public List<Users> getAllUsers() {
		 List<Users> listUsers =  usersRepository.findAll();
		System.out.println(listUsers.size());
		return listUsers;
	}
}
