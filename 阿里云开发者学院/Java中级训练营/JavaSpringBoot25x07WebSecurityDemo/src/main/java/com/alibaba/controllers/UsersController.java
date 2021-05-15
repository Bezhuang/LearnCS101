package com.alibaba.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.alibaba.models.Users;
import com.alibaba.repository.UsersDAO;

@RequestMapping("/Users")
@Controller
public class UsersController {

	@Autowired
	private UsersDAO usersDAO;

	@GetMapping
	public String hello() {
		return "Hello Java Spring Security";
	}

	@PreAuthorize("hasRole('Admin')")
	@RequestMapping("/getAll")
	@ResponseBody
	public List<Users> getAllUsers() {
		List<Users> listUsers = (List<Users>) usersDAO.getAllUsers();
		System.out.println(listUsers.size());
		return listUsers;
	}

	@RequestMapping("/getById/{id}")
	@ResponseBody
	public Users getUserById(@PathVariable int id) {
		System.out.println(id);
		Users user = (Users) usersDAO.getUserById(id);
		return user;
	}
}
