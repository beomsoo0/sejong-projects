function varargout = bouncing_ball(varargin)
% BOUNCING_BALL MATLAB code for bouncing_ball.fig
%      BOUNCING_BALL, by itself, creates a new BOUNCING_BALL or raises the existing
%      singleton*.
%
%      H = BOUNCING_BALL returns the handle to a new BOUNCING_BALL or the handle to
%      the existing singleton*.
%
%      BOUNCING_BALL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BOUNCING_BALL.M with the given input arguments.
%
%      BOUNCING_BALL('Property','Value',...) creates a new BOUNCING_BALL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before bouncing_ball_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to bouncing_ball_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help bouncing_ball

% Last Modified by GUIDE v2.5 11-Nov-2013 19:46:33

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @bouncing_ball_OpeningFcn, ...
                   'gui_OutputFcn',  @bouncing_ball_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before bouncing_ball is made visible.
function bouncing_ball_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to bouncing_ball (see VARARGIN)

% Choose default command line output for bouncing_ball
handles.output = hObject;
disp('Hello!');

% Throw a ball in a random direction
t = linspace(0,2*pi,50);
ball.R = 0.5;
x = ball.R * cos(t); y = ball.R * sin(t);
ball.p = patch( x, y, 'b' ); axis([-10 10 -10 10]);
hold on; plot([-10 10 10 -10 -10], [-10 -10 10 10 -10],'r-', 'LineWidth',5);
hold off; axis off;
ball.x  = x; ball.y  = y;
ball.cx = 0; ball.cy = 0;
ball.px = 0; ball.py = 0;
ball.angle = rand * 2*pi;
ball.d  = 0; ball.dd = 0.5;
handles.ball = ball;
handles.timer   = timer('ExecutionMode', 'FixedRate', 'Period', 0.05, ...
    'TimerFcn', {@move_ball, hObject} );
handles.moving = 0;

[s, Fs] = audioread('BOING.WAV');
handles.p = audioplayer(s(1800:2550),Fs);

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes bouncing_ball wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = bouncing_ball_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
disp('clicked!');
if handles.moving == 0
    start(handles.timer);
    set( hObject, 'String', 'Stop' );
    handles.moving = 1;
else
    stop(handles.timer);
    set( hObject, 'String', 'Play' );
    handles.moving = 0;
end
guidata( hObject, handles );

% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

disp('Bye');
if handles.moving == 1
    stop( handles.timer );
end
delete( handles.timer );
% Hint: delete(hObject) closes the figure
delete(hObject);

function move_ball( obj, event, hfigure )
% update the ball position
handles = guidata( hfigure );
% set(handles.pushbutton1, 'String', num2str(randi([0 9],1)) );
ball = handles.ball;
ball.d = ball.d + ball.dd;
ball.cx = ball.px + ball.d*cos(ball.angle);
ball.cy = ball.py + ball.d*sin(ball.angle);
% boundary check: whether the ball hits a wall or not
if abs(ball.cx) + ball.R >= 10
    % reflect the ball
    ball.angle = pi - ball.angle;
    ball.px = ball.cx; ball.py = ball.cy;
    ball.d  = ball.dd;
    ball.cx = ball.px + ball.d*cos(ball.angle);
    ball.cy = ball.py + ball.d*sin(ball.angle);
%     if isplaying(handles.p), stop(handles.p); end;
    play(handles.p);
elseif abs(ball.cy) + ball.R >= 10
    % reflect the ball
    ball.angle = - ball.angle;
    ball.px = ball.cx; ball.py = ball.cy;
    ball.d  = ball.dd;
    ball.cx = ball.px + ball.d*cos(ball.angle);
    ball.cy = ball.py + ball.d*sin(ball.angle);
%     if isplaying(handles.p), stop(handles.p); end;
    play(handles.p);
end
X = ball.cx + ball.x; Y = ball.cy + ball.y;
set(handles.ball.p, 'XData', X );
set(handles.ball.p, 'YData', Y );
handles.ball = ball;
% set( handles.pushbutton1,'String', 'Play1');
guidata( hfigure, handles);


% --- Executes on key press with focus on figure1 or any of its controls.
function figure1_WindowKeyPressFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  structure with the following fields (see FIGURE)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)
disp(eventdata);
