USE [MY_DB]
GO
/****** Object:  StoredProcedure [dbo].[searchStuIfno]    Script Date: 07/12/2018 17:29:21 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER PROCEDURE [dbo].[searchStuIfno]
	-- Add the parameters for the stored procedure here
	@nID int
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	--SELECT <@Param1, sysname, @p1>, <@Param2, sysname, @p2>
	SELECT * FROM stu_info WHERE num = @nID
END
