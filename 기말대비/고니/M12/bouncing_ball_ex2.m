function varargout = bouncing_ball_ex2(varargin)
% BOUNCING_BALL_EX2 MATLAB code for bouncing_ball_ex2.fig
%      BOUNCING_BALL_EX2, by itself, creates a new BOUNCING_BALL_EX2 or raises the existing
%      singleton*.
%
%      H = BOUNCING_BALL_EX2 returns the handle to a new BOUNCING_BALL_EX2 or the handle to
%      the existing singleton*.
%
%      BOUNCING_BALL_EX2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BOUNCING_BALL_EX2.M with the given input arguments.
%
%      BOUNCING_BALL_EX2('Property','Value',...) creates a new BOUNCING_BALL_EX2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before bouncing_ball_ex2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to bouncing_ball_ex2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help bouncing_ball_ex2

% Last Modified by GUIDE v2.5 11-Nov-2013 17:10:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @bouncing_ball_ex2_OpeningFcn, ...
                   'gui_OutputFcn',  @bouncing_ball_ex2_OutputFcn, ...
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


% --- Executes just before bouncing_ball_ex2 is made visible.
function bouncing_ball_ex2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to bouncing_ball_ex2 (see VARARGIN)

% Choose default command line output for bouncing_ball_ex2
handles.output = hObject;
disp('Hello!');

% Throw a ball in a random direction
t = 0:0.01:2*pi;
ball.R = 0.5;
x = ball.R * cos(t); y = ball.R * sin(t);
ball.p = patch( x, y, 'b' ); axis([-10 10 -10 10]);
hold on; plot([-10 10 10 -10 -10], [-10 -10 10 10 -10],'r-', 'LineWidth',5);
hold off; axis off;
ball.x  = x; ball.y  = y;
ball.cx = 0; ball.cy = 0;
ball.px = 0; ball.py = 0;
ball.angle = rand * 2*pi;
ball.d  = 0; ball.dd = 0.1;
handles.ball = ball;
handles.timer   = timer('ExecutionMode', 'FixedRate', 'Period', 0.01, ...
    'TimerFcn', {@move_ball, hObject} );
handles.moving = 0;

[s, Fs] = audioread('BOING.WAV');
handles.p = audioplayer(s(1800:2550),Fs);

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes bouncing_ball_ex2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = bouncing_ball_ex2_OutputFcn(hObject, eventdata, handles) 
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
guidata( hfigure, handles);


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
handles.ball.dd = get( hObject, 'Value' );
guidata( hObject, handles);

% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on key press with focus on figure1 or any of its controls.
function figure1_WindowKeyPressFcn(hObject, eventdata, handles)
disp(eventdata.Key);
d  = get(handles.slider1, 'Value');
ds = get(handles.slider1, 'SliderStep');
disp(d);
switch eventdata.Key
    case 'downarrow'
        d  = max( get(handles.slider1,'Min'), d - ds(2) );
    case 'uparrow'
        d  = min( get(handles.slider1,'Max'), d + ds(2) );
    otherwise
end
disp(d);
set(handles.slider1, 'Value', d);
handles.ball.dd = d;
guidata( hObject, handles);