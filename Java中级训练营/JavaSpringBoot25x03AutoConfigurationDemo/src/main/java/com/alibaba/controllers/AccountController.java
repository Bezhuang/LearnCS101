package com.alibaba.controllers;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import com.alibaba.models.Users;
import com.alibaba.services.UserServiceImpl;

@Controller
@RequestMapping("/Account")
public class AccountController {
	@Autowired
	private UserServiceImpl  userServiceImpl;
 
	@RequestMapping(value = "/login", method = RequestMethod.GET)
	public String login() {
		System.out.println("打开登录页面");
		return "Account/login";
	}

	@RequestMapping(value = "/login", method = RequestMethod.POST)
	public ModelAndView login(String username, String password, HttpServletRequest
			request, HttpServletResponse response) {
		System.out.println(username);
		System.out.println(password);
		ModelAndView mv = new ModelAndView("redirect:/Home/index");
		try {
			 //Hash密码加密，
			 //SQL注入，防止SQL注入
			 Users user = userServiceImpl.getUserByNameAndPassword(username, password);
			if (user != null) {
				request.getSession().setAttribute("UserName", username);
			} else {
				mv.setViewName("redirect:./login");
			}
		}
		catch (Exception e) {	
			System.out.println(e.getMessage());
		}
		return mv;
	}
}
