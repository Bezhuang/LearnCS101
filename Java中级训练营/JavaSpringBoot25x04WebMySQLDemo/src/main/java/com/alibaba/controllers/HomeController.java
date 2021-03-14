package com.alibaba.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.alibaba.entity.Users;
import com.alibaba.repository.UsersRepository;

@RequestMapping("/Home")
@RestController
public class HomeController {
	@Autowired//自动装配
	private UsersRepository usersRepository;

	//查询所有的用户数据
	@RequestMapping("/getAll")
	public List<Users> getAll() {
		List<Users> listUsers = (List<Users>) usersRepository.findAll();
		return listUsers;
	}
}
