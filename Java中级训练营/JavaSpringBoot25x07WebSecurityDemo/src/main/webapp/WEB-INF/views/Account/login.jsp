<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>

<jsp:include page="head.jsp"></jsp:include>
<br>
<div class= "container" style="max-width:450px;">

	<form class="form-signin" action="<%=request.getContextPath()%>/my/login" method="post">
			<h2 style="text-align: center; font-family: Microsoft YaHei;">登录</h2>
          
           <div class="form-group">
			<label for="username" >账号</label> 
			<br />
			<input type="text" id="username" name="username" class="form-control" placeholder="账号" requiredautofocus>
				</div>
				
		    <div class="form-group">
			 <label for="password" >密码</label>
			<br />		
			<input type="password" id="password" name="password"class="form-control"placeholder="密码" required>
			</div>
			<br />
			
			<input type="checkbox" id="rememberMe" name="rememberMe">
			<label for="rememberMe" >记住密码?</label>
			<br />
			<button type="submit" class="btn btn-lg btn-primary btn-block" >登录</button>
			<br />
			<p><a style="float:left;" href="forgetpassword">忘记密码</a><a  style="float:right;" href="register">注册账号</a></p>
			<br />
		</form>
	</div>

<jsp:include page="foot.jsp"></jsp:include>