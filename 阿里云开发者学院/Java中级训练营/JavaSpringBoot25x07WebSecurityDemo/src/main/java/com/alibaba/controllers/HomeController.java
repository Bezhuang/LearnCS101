package com.alibaba.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import com.alibaba.models.Users;
import com.alibaba.repository.UsersDAO;
import com.alibaba.repository.UsersRepository;

@RequestMapping("/Home")
@RestController
public class HomeController {
	@Autowired
	private UsersRepository usersRepository;
	
	@Autowired
	private UsersDAO usersDAO;
	
	@RequestMapping("/index")
	public List<Users> index() {
		ModelAndView mv = new ModelAndView("index");
		mv.addObject("message", "Hello！ 阿里巴巴Java Spring Boot2.0实战开发课程");
		List<Users> listUsers = (List<Users>) usersRepository.findAll();
		return listUsers;
	}
	
	@RequestMapping("/getAll")
	public List<Users> getAll() {
		List<Users> listUsers = (List<Users>) usersDAO.getAllUsers();
		return listUsers;
	}
	
	@RequestMapping("/getAllUsers")
	@ResponseBody
	public List<Users> getAllUsers() {
		 List<Users> listUsers = (List<Users>) usersDAO.getAllUsers();
		System.out.println(listUsers.size());
		return listUsers;
	}
}
