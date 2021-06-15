function varargout = Button1(varargin)
% BUTTON1 MATLAB code for Button1.fig
%      BUTTON1, by itself, creates a new BUTTON1 or raises the existing
%      singleton*.
%
%      H = BUTTON1 returns the handle to a new BUTTON1 or the handle to
%      the existing singleton*.
%
%      BUTTON1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BUTTON1.M with the given input arguments.
%
%      BUTTON1('Property','Value',...) creates a new BUTTON1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Button1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Button1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Button1

% Last Modified by GUIDE v2.5 16-May-2015 08:47:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Button1_OpeningFcn, ...
                   'gui_OutputFcn',  @Button1_OutputFcn, ...
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


% --- Executes just before Button1 is made visible.
function Button1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Button1 (see VARARGIN)

% Choose default command line output for Button1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

a  = handles.axes1;
axes(a);
im = imagesc(imread('button1.png'));
axis image;

set(a,'ButtonDownFcn','disp(''axes button down'')')
%the button doen fcn will not work until the image hit test is off
set(im,'HitTest','off');

%now set an image button doen fcn
set(im,'ButtonDownFcn','disp(''image button down'')')
set(im,'ButtonUpFcn','disp(''image button up'')')
%the image funtion will not fire until hit test is turned on
set(im,'HitTest','on'); %now image button function will work
% UIWAIT makes Button1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Button1_OutputFcn(hObject, eventdata, handles) 
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
G = imread('button1.png');
set(hObject, 'CData', G);
disp('Clicked');


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over pushbutton1.
function pushbutton1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
G = imread('button2.png');
set(hObject, 'CData', G);
disp('Pressed');
