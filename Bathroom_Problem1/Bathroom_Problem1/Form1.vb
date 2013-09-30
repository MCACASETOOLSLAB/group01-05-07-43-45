Public Class Form1
    'Dim A1 As UInteger = 0.2, b1 As Integer

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Private Sub PictureBox1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p4.Click

    End Sub

    Private Sub PictureBox5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p5.Click

    End Sub

    Private Sub PictureBox2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p1.Click

    End Sub

    Private Sub PictureBox3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p2.Click

    End Sub

    Private Sub PictureBox4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p3.Click

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Button3.Enabled = True
        Button5.Enabled = True
        Button1.Enabled = False
        p1.Visible = False
        p6.Visible = False
        p4.Visible = True
        p9.Visible = False
        p5.Visible = True
        p10.Visible = False
        While (p2.Location.X >= 30)
            p2.Left = p2.Left - 1
            p3.Left = p3.Left - 1
            p7.Left = p7.Left - 1
            p8.Left = p8.Left - 1

        End While

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        '  MsgBox("The current time is " & Now.ToShortTimeString)
        Button3.Enabled = False
        Button5.Enabled = False

        While (p6.Location.X <= 330 And p6.Location.Y >= 55)

            p6.Top = p6.Top - 1
            p6.Left = p6.Left + 1
            p1.Visible = False
            p6.Visible = True
            p4.Visible = False
            p9.Visible = True
            p5.Visible = False
            p10.Visible = True
        End While
            End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Button1.Enabled = False
        Button5.Enabled = False
        Button2.Enabled = False
        p6.Visible = False
        p1.Visible = False
        While (p7.Location.X <= 320 And p7.Location.Y >= 55)

            p7.Top = p7.Top - 1
            p7.Left = p7.Left + 1
            p2.Visible = False
            p7.Visible = True
            p4.Visible = False
            p9.Visible = True
            p5.Visible = False
            p10.Visible = True
        End While
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Button3.Enabled = False
        Button5.Enabled = True

        p1.Visible = False
        p6.Visible = False
        p4.Visible = True
        p9.Visible = False
        p5.Visible = True
        p10.Visible = False

        p7.Visible = False
        While (p3.Location.X >= 30)
            p3.Left = p3.Left - 1
            p8.Left = p8.Left - 1

        End While

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Button3.Enabled = False
        ' Button5.Enabled = False
        Button4.Enabled = False
        Button2.Enabled = False
        p6.Visible = False
        p1.Visible = False
        p2.Visible = False
        p7.Visible = False
        While (p8.Location.X <= 320 And p8.Location.Y >= 25)

            p8.Top = p8.Top - 1
            p8.Left = p8.Left + 1
            p8.Visible = True
            p4.Visible = False
            p3.Visible = False

            p9.Visible = True
            p5.Visible = False
            p10.Visible = True
        End While
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Button5.Enabled = False
        p3.Visible = False
        p8.Visible = False
        p4.Visible = True
        p5.Visible = True
        Button6.Enabled = False
        'MsgBox("no more people in queue")

    End Sub


 
    Private Sub p9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles p9.Click

    End Sub
End Class
