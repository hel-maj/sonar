/* ===== 23e115e40 telegram.handlers.fishing_handle:132 ===== */
/* ghidra_name=FUN_23e115e40 entry=23e115e40 size=5967 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e115e40(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong *plVar14;
  undefined8 uVar15;
  longlong *plStack_88;
  longlong *plStack_80;
  longlong *plStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar8 = _DAT_23eeab138;
  if (_DAT_23eeab138 == (longlong *)0x0) {
LAB_23e115e7c:
    _DAT_23eeab138 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab130,DAT_23eeab180,0x10);
  }
  else {
    lVar7 = *_DAT_23eeab138;
    if (1 < lVar7) {
      *_DAT_23eeab138 = lVar7 + -1;
      goto LAB_23e115e7c;
    }
    if (_DAT_23eeab138[2] != 0) {
      *_DAT_23eeab138 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e115e7c;
    }
  }
  plVar2 = _DAT_23eeab138;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeab138 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  _DAT_23eeab138[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar8;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar7 = FUN_23e901290();
  if (lVar7 == 0) {
LAB_23e116e40:
    plVar9 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_78,DAT_23eea9200);
    uVar13 = 0x86;
    plVar12 = DAT_23ed6a4f8;
    plVar10 = plStack_78;
    uVar15 = uStack_70;
    plVar8 = plStack_68;
    goto joined_r0x00023e116e6d;
  }
  iVar5 = FUN_23a35f020(lVar7);
  if (iVar5 == -1) {
LAB_23e116c90:
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar10 = *(longlong **)(param_1 + 0x60);
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 0x86;
    plVar9 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
    goto joined_r0x00023e116e6d;
  }
  if (iVar5 == 0) {
LAB_23e115f29:
    plVar10 = _DAT_23eea9458;
    lVar7 = *(longlong *)(param_1 + 0x38);
    lVar1 = *(longlong *)(lVar7 + 8);
    *_DAT_23eea9458 = *_DAT_23eea9458 + 1;
    plVar8 = *(longlong **)(lVar1 + 0x28);
    plVar2 = (longlong *)plVar8[2];
    *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(lVar1 + 0x30);
    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
    if (plVar2 != (longlong *)0x0) {
      plVar8[2] = 0;
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))();
      }
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8[0xf] = 0;
    return plVar10;
  }
  lVar7 = FUN_23e901290();
  if (lVar7 == 0) goto LAB_23e116e40;
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea9220);
  if (plVar8 == (longlong *)0x0) {
    plVar10 = *(longlong **)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0x86;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    goto joined_r0x00023e116e6d;
  }
  uVar6 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (uVar6 == 0xffffffff) goto LAB_23e116c90;
  if ((uVar6 & 1) == 0) goto LAB_23e115f29;
  lVar7 = FUN_23e9013c0();
  if (lVar7 == 0) {
    plVar14 = (longlong *)0x0;
    FUN_23e915740(param_1,&plStack_78,DAT_23eea9210);
    uVar13 = 0x89;
    plVar9 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar10 = plStack_78;
    uVar15 = uStack_70;
    plVar8 = plStack_68;
    goto joined_r0x00023e116e6d;
  }
  *(undefined4 *)(plVar2 + 5) = 0x89;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,lVar7,DAT_23eea9218);
  plVar8 = _DAT_23eea9468;
  plVar14 = _DAT_23eea9460;
  if (plVar9 == (longlong *)0x0) {
    plVar10 = *(longlong **)(param_1 + 0x60);
    plVar14 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0x89;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = DAT_23ed6a4f8;
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    goto joined_r0x00023e116e6d;
  }
  lVar7 = *(longlong *)(param_1 + 0x10);
  plVar12 = *(longlong **)(lVar7 + 0xe28);
  plStack_88 = _DAT_23eea9460;
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar1 = plVar12[3];
    *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
    *(longlong *)(lVar7 + 0xe28) = lVar1;
    *plVar12 = 1;
  }
  pcVar4 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar1 = plVar12[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar12 + -2;
  plVar12[-2] = lVar7;
  plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar12 + -2;
  *plVar8 = *plVar8 + 1;
  plVar12[3] = (longlong)plVar8;
  lVar7 = FUN_23e901290();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&plStack_78,DAT_23eea9200);
    plVar8 = plStack_68;
    uVar15 = uStack_70;
    plVar10 = plStack_78;
LAB_23e116f4c:
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
  }
  else {
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eea9470);
    if (plVar8 == (longlong *)0x0) {
      plVar10 = *(longlong **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e116f4c;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce48);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    uVar15 = DAT_23ed6cd28;
    if (plVar10 == (longlong *)0x0) {
LAB_23e116f30:
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = *(longlong **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e116f4c;
    }
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar8 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar8 != (longlong *)0x0) {
        *plVar8 = *plVar8 + 1;
        DAT_23ed6a4c0 = plVar8;
        goto LAB_23e11616f;
      }
LAB_23e11730a:
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e11731d:
      plVar10 = *(longlong **)(param_1 + 0x60);
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e11728c:
      uVar13 = 0x91;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e116e6d;
    }
LAB_23e11616f:
    uStack_70 = uVar15;
    plStack_78 = plVar10;
    lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar7 == 0) goto LAB_23e116f30;
    plVar12[4] = lVar7;
    plVar8 = _DAT_23eea9478;
    *_DAT_23eea9478 = *_DAT_23eea9478 + 1;
    plVar12[5] = (longlong)plVar8;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar8 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
      FUN_23e8d97b0(&plStack_88,plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar14 = plStack_88;
      plVar8 = _DAT_23eea9480;
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar12 = *(longlong **)(lVar7 + 0xe28);
      plStack_80 = plStack_88;
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar1 = plVar12[3];
        *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
        *(longlong *)(lVar7 + 0xe28) = lVar1;
        *plVar12 = 1;
      }
      pcVar4 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar12[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar12 + -2;
      plVar12[-2] = lVar7;
      plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar7 + 8) = plVar12 + -2;
      *plVar8 = *plVar8 + 1;
      plVar12[3] = (longlong)plVar8;
      lVar7 = FUN_23e901290();
      if (lVar7 == 0) {
        FUN_23e915740(param_1,&plStack_78,DAT_23eea9200);
        plVar8 = plStack_68;
        uVar15 = uStack_70;
        plVar10 = plStack_78;
LAB_23e116fcc:
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      else {
        plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eea9488);
        if (plVar8 == (longlong *)0x0) {
          plVar10 = *(longlong **)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e116fcc;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eea9490);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        if (plVar10 == (longlong *)0x0) {
LAB_23e116fb0:
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar10 = *(longlong **)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e116fcc;
        }
        *(undefined4 *)(plVar2 + 5) = 0x8e;
        plVar8 = (longlong *)FUN_23e91a870(param_1);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        uVar15 = DAT_23ed6cd28;
        if (plVar8 == (longlong *)0x0) goto LAB_23e116fb0;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar10 == (longlong *)0x0) goto LAB_23e11730a;
          *plVar10 = *plVar10 + 1;
          DAT_23ed6a4c0 = plVar10;
        }
        uStack_70 = uVar15;
        plStack_78 = plVar8;
        lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8 = _DAT_23eea9498;
        if (lVar7 == 0) goto LAB_23e116fb0;
        plVar12[4] = lVar7;
        *plVar8 = *plVar8 + 1;
        plVar12[5] = (longlong)plVar8;
        plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar8 != (longlong *)0x0) {
          FUN_23e8d97b0(&plStack_80);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plStack_78 = plStack_80;
          FUN_23e8d97b0(&plStack_78,_DAT_23eea94a0);
          plVar14 = plStack_78;
          plVar8 = _DAT_23eea94a8;
          lVar7 = *(longlong *)(param_1 + 0x10);
          plVar12 = *(longlong **)(lVar7 + 0xe28);
          if (plVar12 == (longlong *)0x0) {
            plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar1 = plVar12[3];
            *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
            *(longlong *)(lVar7 + 0xe28) = lVar1;
            *plVar12 = 1;
          }
          pcVar4 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
          lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
          lVar1 = plVar12[-1];
          puVar3 = *(undefined8 **)(lVar7 + 8);
          *puVar3 = plVar12 + -2;
          plVar12[-2] = lVar7;
          plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
          *(longlong **)(lVar7 + 8) = plVar12 + -2;
          *plVar8 = *plVar8 + 1;
          plVar12[3] = (longlong)plVar8;
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
          if (plVar8 == (longlong *)0x0) {
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar10 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar15 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0x91;
            plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8,DAT_23eea9238);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (plVar11 == (longlong *)0x0) {
              plVar10 = *(longlong **)(param_1 + 0x60);
              uVar15 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              iVar5 = FUN_23a35f020(plVar11);
              lVar7 = *plVar11 + -1;
              if (iVar5 != -1) {
                *plVar11 = lVar7;
                if (lVar7 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                plVar8 = _DAT_23eea93b0;
                if (iVar5 != 0) {
                  plVar8 = _DAT_23eea93a8;
                }
                *plVar8 = *plVar8 + 1;
                plVar12[4] = (longlong)plVar8;
                plVar8 = _DAT_23eea94b0;
                *_DAT_23eea94b0 = *_DAT_23eea94b0 + 1;
                plVar12[5] = (longlong)plVar8;
                plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (plVar8 == (longlong *)0x0) goto LAB_23e11731d;
                FUN_23e8d97b0(&plStack_78,plVar8);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                plVar14 = plStack_78;
                plVar8 = _DAT_23eea94b8;
                lVar7 = *(longlong *)(param_1 + 0x10);
                plVar12 = *(longlong **)(lVar7 + 0xe28);
                if (plVar12 == (longlong *)0x0) {
                  plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                }
                else {
                  lVar1 = plVar12[3];
                  *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                  *(longlong *)(lVar7 + 0xe28) = lVar1;
                  *plVar12 = 1;
                }
                pcVar4 = _PyRuntime_exref;
                *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
                lVar1 = plVar12[-1];
                puVar3 = *(undefined8 **)(lVar7 + 8);
                *puVar3 = plVar12 + -2;
                plVar12[-2] = lVar7;
                plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
                *(longlong **)(lVar7 + 8) = plVar12 + -2;
                *plVar8 = *plVar8 + 1;
                plVar12[3] = (longlong)plVar8;
                plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
                uVar15 = DAT_23eea9250;
                if (plVar8 == (longlong *)0x0) {
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  plVar10 = *(longlong **)(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar15 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e117379:
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0x92;
                  plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8,uVar15);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar11 == (longlong *)0x0) {
                    plVar10 = *(longlong **)(param_1 + 0x60);
                    uVar15 = *(undefined8 *)(param_1 + 0x68);
                    plVar8 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    goto LAB_23e117379;
                  }
                  iVar5 = FUN_23a35f020(plVar11);
                  lVar7 = *plVar11 + -1;
                  if (iVar5 == -1) {
                    plVar10 = *(longlong **)(param_1 + 0x60);
                    uVar15 = *(undefined8 *)(param_1 + 0x68);
                    plVar8 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar11 = lVar7;
                    if (lVar7 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    goto LAB_23e117379;
                  }
                  *plVar11 = lVar7;
                  if (lVar7 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  plVar8 = _DAT_23eea93b0;
                  if (iVar5 != 0) {
                    plVar8 = _DAT_23eea93a8;
                  }
                  *plVar8 = *plVar8 + 1;
                  plVar12[4] = (longlong)plVar8;
                  plVar8 = _DAT_23eea94b0;
                  *_DAT_23eea94b0 = *_DAT_23eea94b0 + 1;
                  plVar12[5] = (longlong)plVar8;
                  plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar8 != (longlong *)0x0) {
                    FUN_23e8d97b0(&plStack_78,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    plVar14 = plStack_78;
                    plVar8 = _DAT_23eea94c0;
                    lVar7 = *(longlong *)(param_1 + 0x10);
                    plVar12 = *(longlong **)(lVar7 + 0xe28);
                    if (plVar12 == (longlong *)0x0) {
                      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                    }
                    else {
                      lVar1 = plVar12[3];
                      *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                      *(longlong *)(lVar7 + 0xe28) = lVar1;
                      *plVar12 = 1;
                    }
                    pcVar4 = _PyRuntime_exref;
                    *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                    lVar7 = *(longlong *)
                             (*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
                    lVar1 = plVar12[-1];
                    puVar3 = *(undefined8 **)(lVar7 + 8);
                    *puVar3 = plVar12 + -2;
                    plVar12[-2] = lVar7;
                    plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
                    *(longlong **)(lVar7 + 8) = plVar12 + -2;
                    *plVar8 = *plVar8 + 1;
                    plVar12[3] = (longlong)plVar8;
                    plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
                    uVar15 = DAT_23eea9268;
                    if (plVar8 == (longlong *)0x0) {
                      plVar8 = *(longlong **)(param_1 + 0x70);
                      plVar10 = *(longlong **)(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar15 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e117417:
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                    }
                    else {
                      *(undefined4 *)(plVar2 + 5) = 0x93;
                      plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8,uVar15);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar11 == (longlong *)0x0) {
                        plVar10 = *(longlong **)(param_1 + 0x60);
                        uVar15 = *(undefined8 *)(param_1 + 0x68);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        goto LAB_23e117417;
                      }
                      iVar5 = FUN_23a35f020(plVar11);
                      lVar7 = *plVar11 + -1;
                      if (iVar5 == -1) {
                        plVar10 = *(longlong **)(param_1 + 0x60);
                        uVar15 = *(undefined8 *)(param_1 + 0x68);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar11 = lVar7;
                        if (lVar7 == 0) {
                          FUN_23a334bc0(plVar11);
                        }
                        goto LAB_23e117417;
                      }
                      *plVar11 = lVar7;
                      if (lVar7 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      plVar8 = _DAT_23eea93b0;
                      if (iVar5 != 0) {
                        plVar8 = _DAT_23eea93a8;
                      }
                      *plVar8 = *plVar8 + 1;
                      plVar12[4] = (longlong)plVar8;
                      plVar8 = _DAT_23eea94b0;
                      *_DAT_23eea94b0 = *_DAT_23eea94b0 + 1;
                      plVar12[5] = (longlong)plVar8;
                      plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      if (plVar8 != (longlong *)0x0) {
                        FUN_23e8d97b0(&plStack_78,plVar8);
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        plVar14 = plStack_78;
                        plVar8 = _DAT_23eea94c8;
                        lVar7 = *(longlong *)(param_1 + 0x10);
                        plVar12 = *(longlong **)(lVar7 + 0xe28);
                        if (plVar12 == (longlong *)0x0) {
                          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                        }
                        else {
                          lVar1 = plVar12[3];
                          *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                          *(longlong *)(lVar7 + 0xe28) = lVar1;
                          *plVar12 = 1;
                        }
                        pcVar4 = _PyRuntime_exref;
                        *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                        lVar7 = *(longlong *)
                                 (*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
                        lVar1 = plVar12[-1];
                        puVar3 = *(undefined8 **)(lVar7 + 8);
                        *puVar3 = plVar12 + -2;
                        plVar12[-2] = lVar7;
                        plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
                        *(longlong **)(lVar7 + 8) = plVar12 + -2;
                        *plVar8 = *plVar8 + 1;
                        plVar12[3] = (longlong)plVar8;
                        plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
                        uVar15 = DAT_23eea9280;
                        if (plVar8 == (longlong *)0x0) {
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          plVar10 = *(longlong **)(param_1 + 0x60);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar15 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e1174d8:
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                        }
                        else {
                          *(undefined4 *)(plVar2 + 5) = 0x94;
                          plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8,uVar15);
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          if (plVar11 == (longlong *)0x0) {
                            plVar10 = *(longlong **)(param_1 + 0x60);
                            uVar15 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            goto LAB_23e1174d8;
                          }
                          iVar5 = FUN_23a35f020(plVar11);
                          lVar7 = *plVar11 + -1;
                          if (iVar5 == -1) {
                            plVar10 = *(longlong **)(param_1 + 0x60);
                            uVar15 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar7;
                            if (lVar7 == 0) {
                              FUN_23a334bc0(plVar11);
                            }
                            goto LAB_23e1174d8;
                          }
                          *plVar11 = lVar7;
                          if (lVar7 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          plVar8 = _DAT_23eea93b0;
                          if (iVar5 != 0) {
                            plVar8 = _DAT_23eea93a8;
                          }
                          *plVar8 = *plVar8 + 1;
                          plVar12[4] = (longlong)plVar8;
                          plVar8 = _DAT_23eea94b0;
                          *_DAT_23eea94b0 = *_DAT_23eea94b0 + 1;
                          plVar12[5] = (longlong)plVar8;
                          plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (plVar8 != (longlong *)0x0) {
                            FUN_23e8d97b0(&plStack_78,plVar8);
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                            }
                            plVar14 = plStack_78;
                            plVar8 = _DAT_23eea94d0;
                            lVar7 = *(longlong *)(param_1 + 0x10);
                            plVar12 = *(longlong **)(lVar7 + 0xe28);
                            if (plVar12 == (longlong *)0x0) {
                              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar1 = plVar12[3];
                              *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                              *(longlong *)(lVar7 + 0xe28) = lVar1;
                              *plVar12 = 1;
                            }
                            pcVar4 = _PyRuntime_exref;
                            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                            lVar7 = *(longlong *)
                                     (*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
                            lVar1 = plVar12[-1];
                            puVar3 = *(undefined8 **)(lVar7 + 8);
                            *puVar3 = plVar12 + -2;
                            plVar12[-2] = lVar7;
                            plVar12[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
                            *(longlong **)(lVar7 + 8) = plVar12 + -2;
                            *plVar8 = *plVar8 + 1;
                            plVar12[3] = (longlong)plVar8;
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
                            if (plVar8 == (longlong *)0x0) {
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              plVar10 = *(longlong **)(param_1 + 0x60);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar15 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e117596:
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                            }
                            else {
                              *(undefined4 *)(plVar2 + 5) = 0x95;
                              plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar8);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                FUN_23a334bc0(plVar8);
                              }
                              if (plVar11 == (longlong *)0x0) {
                                plVar10 = *(longlong **)(param_1 + 0x60);
                                uVar15 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                goto LAB_23e117596;
                              }
                              iVar5 = FUN_23a35f020();
                              lVar7 = *plVar11 + -1;
                              if (iVar5 == -1) {
                                plVar10 = *(longlong **)(param_1 + 0x60);
                                uVar15 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar11 = lVar7;
                                if (lVar7 == 0) {
                                  FUN_23a334bc0(plVar11);
                                }
                                goto LAB_23e117596;
                              }
                              *plVar11 = lVar7;
                              if (lVar7 == 0) {
                                FUN_23a334bc0(plVar11);
                              }
                              plVar8 = _DAT_23eea93b0;
                              if (iVar5 != 0) {
                                plVar8 = _DAT_23eea93a8;
                              }
                              *plVar8 = *plVar8 + 1;
                              plVar12[4] = (longlong)plVar8;
                              plVar8 = _DAT_23eea94b0;
                              *_DAT_23eea94b0 = *_DAT_23eea94b0 + 1;
                              plVar12[5] = (longlong)plVar8;
                              plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              if (plVar8 != (longlong *)0x0) {
                                FUN_23e8d97b0(&plStack_78,plVar8);
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  FUN_23a334bc0(plVar8);
                                }
                                plVar8 = plStack_78;
                                FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                *plVar8 = *plVar8 + 1;
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  FUN_23a334bc0(plVar9);
                                }
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 != 0) {
                                  return plVar8;
                                }
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                                return plVar8;
                              }
                              plVar10 = *(longlong **)(param_1 + 0x60);
                              uVar15 = *(undefined8 *)(param_1 + 0x68);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                            }
                            uVar13 = 0x95;
                            plVar12 = DAT_23ed6a4f8;
                            goto joined_r0x00023e116e6d;
                          }
                          plVar10 = *(longlong **)(param_1 + 0x60);
                          uVar15 = *(undefined8 *)(param_1 + 0x68);
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                        }
                        uVar13 = 0x94;
                        plVar12 = DAT_23ed6a4f8;
                        goto joined_r0x00023e116e6d;
                      }
                      plVar10 = *(longlong **)(param_1 + 0x60);
                      uVar15 = *(undefined8 *)(param_1 + 0x68);
                      plVar8 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                    }
                    uVar13 = 0x93;
                    plVar12 = DAT_23ed6a4f8;
                    goto joined_r0x00023e116e6d;
                  }
                  plVar10 = *(longlong **)(param_1 + 0x60);
                  uVar15 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                uVar13 = 0x92;
                plVar12 = DAT_23ed6a4f8;
                goto joined_r0x00023e116e6d;
              }
              plVar10 = *(longlong **)(param_1 + 0x60);
              uVar15 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar11 = lVar7;
              if (lVar7 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
            }
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          goto LAB_23e11728c;
        }
        plVar10 = *(longlong **)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      uVar13 = 0x8e;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e116e6d;
    }
    plVar10 = *(longlong **)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  uVar13 = 0x8d;
  plVar14 = (longlong *)0x0;
  plVar12 = DAT_23ed6a4f8;
joined_r0x00023e116e6d:
  DAT_23ed6a4f8 = plVar12;
  if (plVar8 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar12;
    }
    pcVar4 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar13;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar1 = plVar11[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar8;
    if ((longlong *)plVar8[3] != plVar2) {
      if (plVar12 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar12;
      }
      pcVar4 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(pcVar4 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar13;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar1 = plVar11[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar8;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar8;
      if (lVar1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar2,&DAT_23ec5a08f,plVar9,plVar14);
  if (_DAT_23eeab138 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eeab138 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar2 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  FUN_23a33aa70(param_1,plVar10,uVar15,plVar11);
  return (longlong *)0x0;
}
