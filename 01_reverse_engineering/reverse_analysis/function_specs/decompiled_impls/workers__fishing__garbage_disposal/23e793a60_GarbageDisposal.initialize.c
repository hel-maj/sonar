/* ===== 23e793a60 workers.fishing.garbage_disposal:180 ===== */
/* ghidra_name=FUN_23e793a60 entry=23e793a60 size=5451 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e793a60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  longlong *plStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar8 = _DAT_23eedac60;
  plVar1 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eedac60 == (longlong *)0x0) {
LAB_23e793ab7:
    _DAT_23eedac60 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac58,DAT_23eedacf8,0x18);
  }
  else {
    lVar10 = *_DAT_23eedac60;
    if (1 < lVar10) {
      *_DAT_23eedac60 = lVar10 + -1;
      goto LAB_23e793ab7;
    }
    if (_DAT_23eedac60[2] != 0) {
      *_DAT_23eedac60 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e793ab7;
    }
  }
  plVar3 = _DAT_23eedac60;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedac60 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eedac60[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar3 + 5) = 0xb6;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed8310);
  if (plVar8 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0xb6;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
LAB_23e7943af:
    uVar16 = uVar15;
    if (plStack_68 == (longlong *)0x0) {
LAB_23e793d50:
      plVar12 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar14 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar3;
      plVar12[2] = 0;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar14 + 0x1f8);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar15;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
        (**(code **)(plStack_68[1] + 0x30))(plStack_68);
      }
      goto LAB_23e794471;
    }
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82a8);
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0xb7;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      goto LAB_23e7943af;
    }
    *(undefined4 *)(plVar3 + 5) = 0xb7;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed8318);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      iVar6 = FUN_23a35f020(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (iVar6 == -1) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar15 = 0xb7;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7943af;
      }
      if (iVar6 == 0) {
        uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar3 + 5) = 0xb8;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed8320);
        if (plVar8 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0xb8;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e7943af;
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        lVar10 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e793c3e:
        pcVar14 = _Py_FalseStruct_exref;
        *(longlong *)_Py_FalseStruct_exref = lVar10 + 1;
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar10 + 0x28);
        plVar12 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar12 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e793cbd;
LAB_23e793cad:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
LAB_23e793cbd:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar14;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar14;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed82a8);
      if (plVar8 == (longlong *)0x0) {
LAB_23e794380:
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar17 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0xbc;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed8328);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e794380;
        plVar12 = (longlong *)FUN_23a388310(plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e794380;
        plVar8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar8 == (longlong *)0x0) &&
           (plVar8 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar8 == (longlong *)0x0))
        {
          plVar9 = (longlong *)0x0;
        }
        else {
          plVar9 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (((plVar9 != (longlong *)0x0) ||
              (plVar9 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2), plVar9 != (longlong *)0x0
              )) && (cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar12,2), cVar5 != '\0')) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
            plVar11 = _DAT_23eed8330;
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar12 = *(longlong **)(lVar10 + 0xe30);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
            }
            else {
              lVar2 = plVar12[3];
              *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
              *(longlong *)(lVar10 + 0xe30) = lVar2;
              *plVar12 = 1;
            }
            pcVar14 = _PyRuntime_exref;
            plVar12[6] = 0;
            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar12[-1];
            puVar4 = *(undefined8 **)(lVar10 + 8);
            *puVar4 = plVar12 + -2;
            plVar12[-2] = lVar10;
            plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar10 + 8) = plVar12 + -2;
            plVar13 = DAT_23ed6a4c0;
            *plVar11 = *plVar11 + 1;
            plVar12[3] = (longlong)plVar11;
            uVar17 = DAT_23ed6cd28;
            if (plVar13 == (longlong *)0x0) {
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar13 != (longlong *)0x0) {
                *plVar13 = *plVar13 + 1;
                DAT_23ed6a4c0 = plVar13;
                goto LAB_23e793fd7;
              }
LAB_23e794d46:
              PyErr_PrintEx(0);
              Py_Exit(1);
LAB_23e794d59:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xcb;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7943af;
            }
LAB_23e793fd7:
            uStack_80 = uVar17;
            plStack_88 = plVar8;
            lVar10 = FUN_23e94ed00(param_1,plVar13,&plStack_88);
            if (lVar10 == 0) {
LAB_23e794798:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xbd;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            else {
              plVar12[4] = lVar10;
              plVar11 = DAT_23eed8338;
              *DAT_23eed8338 = *DAT_23eed8338 + 1;
              plVar12[5] = (longlong)plVar11;
              uVar17 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar11 == (longlong *)0x0) goto LAB_23e794d46;
                *plVar11 = *plVar11 + 1;
                DAT_23ed6a4c0 = plVar11;
              }
              uStack_80 = uVar17;
              plStack_88 = plVar9;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_88);
              if (lVar10 == 0) goto LAB_23e794798;
              plVar12[6] = lVar10;
              plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar11 == (longlong *)0x0) {
LAB_23e794730:
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xbd;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7943af;
              }
              *(undefined4 *)(plVar3 + 5) = 0xbd;
              plVar12 = (longlong *)FUN_23e914090(param_1,uVar7);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e794730;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              iVar6 = FUN_23e97a530(plVar8,_DAT_23eed8340);
              if (iVar6 == -1) {
LAB_23e794c40:
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xbf;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7943af;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,_DAT_23eed8348);
                if (iVar6 == -1) goto LAB_23e794c40;
                if (iVar6 != 1) goto LAB_23e794103;
                cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed82b0,_DAT_23eed8350);
                if (cVar5 == '\0') {
                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar15 = 0xc0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7943af;
                }
                lVar10 = *(longlong *)(DAT_23eed8080 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eed8080,DAT_23eed8358);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e794da4;
                  lVar10 = *plVar12;
LAB_23e794d9b:
                  if (lVar10 == 0) goto LAB_23e794da4;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15418;
                    iVar6 = _DAT_23ec15418;
                    _DAT_23ec15418 = _DAT_23ec15418 + 1;
                  }
                  if (_DAT_23ec15400 != iVar6) {
                    _DAT_23ec15400 = iVar6;
                    _DAT_23eedac48 =
                         FUN_23e8cbd60(lVar10,DAT_23eed8358,*(undefined8 *)(DAT_23eed8358 + 0x18));
                  }
                  if (-1 < _DAT_23eedac48) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedac48 * 0x10) != 0) goto LAB_23e7949ed;
                    _DAT_23eedac48 =
                         FUN_23e8cbd60(lVar10,DAT_23eed8358,*(undefined8 *)(DAT_23eed8358 + 0x18));
                    if (-1 < _DAT_23eedac48) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedac48 * 0x10);
                      goto LAB_23e794d9b;
                    }
                  }
LAB_23e794da4:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed8358);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xc1;
                    FUN_23e915740(param_1,auStack_78,DAT_23eed8358);
                    goto LAB_23e7943af;
                  }
                }
LAB_23e7949ed:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed82b8);
                if (cVar5 == '\0') {
                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc1;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed8360,DAT_23ed6cd28);
                  if (cVar5 == '\0') {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 0xc2;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0xc3;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed8368);
                    if (plVar12 == (longlong *)0x0) {
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_68 = *(longlong **)(param_1 + 0x70);
                      uVar15 = 0xc3;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
LAB_23e794a50:
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      *(undefined4 *)(plVar3 + 5) = 0xcf;
                      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed83b0);
                      if (plVar12 != (longlong *)0x0) {
                        iVar6 = FUN_23a35f020(plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        if (iVar6 != -1) {
                          if (iVar6 == 0) goto LAB_23e794313;
                          FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                          pcVar14 = _Py_TrueStruct_exref;
                          *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          goto LAB_23e793cad;
                        }
                      }
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_68 = *(longlong **)(param_1 + 0x70);
                      uVar15 = 0xcf;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                  }
                }
                goto LAB_23e7943af;
              }
LAB_23e794103:
              iVar6 = FUN_23e97a530(plVar8,_DAT_23eed8370);
              if (iVar6 == -1) {
LAB_23e794cae:
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xc4;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7943af;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,_DAT_23eed8378);
                if (iVar6 == -1) goto LAB_23e794cae;
                if (iVar6 != 1) goto LAB_23e794124;
                cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed82b0,_DAT_23eed8380);
                if (cVar5 == '\0') {
                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc5;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7943af;
                }
                lVar10 = *(longlong *)(DAT_23eed8080 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eed8080,DAT_23eed8388);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e794e39;
                  lVar10 = *plVar12;
LAB_23e794e30:
                  if (lVar10 == 0) goto LAB_23e794e39;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15418;
                    iVar6 = _DAT_23ec15418;
                    _DAT_23ec15418 = _DAT_23ec15418 + 1;
                  }
                  if (_DAT_23ec15404 != iVar6) {
                    _DAT_23ec15404 = iVar6;
                    _DAT_23eedac50 =
                         FUN_23e8cbd60(lVar10,DAT_23eed8388,*(undefined8 *)(DAT_23eed8388 + 0x18));
                  }
                  if (-1 < _DAT_23eedac50) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedac50 * 0x10) != 0) goto LAB_23e794bac;
                    _DAT_23eedac50 =
                         FUN_23e8cbd60(lVar10,DAT_23eed8388,*(undefined8 *)(DAT_23eed8388 + 0x18));
                    if (-1 < _DAT_23eedac50) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedac50 * 0x10);
                      goto LAB_23e794e30;
                    }
                  }
LAB_23e794e39:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed8388);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xc6;
                    FUN_23e915740(param_1,auStack_78,DAT_23eed8388);
                    goto LAB_23e7943af;
                  }
                }
LAB_23e794bac:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed82b8);
                if (cVar5 == '\0') {
                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc6;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed8360,_DAT_23eed8390);
                  if (cVar5 == '\0') {
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 199;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 200;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed8398);
                    if (plVar12 != (longlong *)0x0) goto LAB_23e794a50;
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 200;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                goto LAB_23e7943af;
              }
LAB_23e794124:
              uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = _DAT_23eed83a0;
              lVar10 = *(longlong *)(param_1 + 0x10);
              plVar12 = *(longlong **)(lVar10 + 0xe30);
              if (plVar12 == (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
              }
              else {
                lVar2 = plVar12[3];
                *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
                *(longlong *)(lVar10 + 0xe30) = lVar2;
                *plVar12 = 1;
              }
              pcVar14 = _PyRuntime_exref;
              plVar12[6] = 0;
              *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
              lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
              lVar2 = plVar12[-1];
              puVar4 = *(undefined8 **)(lVar10 + 8);
              *puVar4 = plVar12 + -2;
              plVar12[-2] = lVar10;
              plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
              *(longlong **)(lVar10 + 8) = plVar12 + -2;
              plVar13 = DAT_23ed6a4c0;
              *plVar11 = *plVar11 + 1;
              plVar12[3] = (longlong)plVar11;
              uVar17 = DAT_23ed6cd28;
              if (plVar13 == (longlong *)0x0) {
                plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar13 == (longlong *)0x0) goto LAB_23e794d46;
                *plVar13 = *plVar13 + 1;
                DAT_23ed6a4c0 = plVar13;
              }
              uStack_80 = uVar17;
              plStack_88 = plVar8;
              lVar10 = FUN_23e94ed00(param_1,plVar13,&plStack_88);
              if (lVar10 != 0) {
                plVar12[4] = lVar10;
                plVar11 = DAT_23eed8338;
                *DAT_23eed8338 = *DAT_23eed8338 + 1;
                plVar12[5] = (longlong)plVar11;
                uVar17 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar11 == (longlong *)0x0) goto LAB_23e794d46;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_80 = uVar17;
                plStack_88 = plVar9;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_88);
                if (lVar10 != 0) {
                  plVar12[6] = lVar10;
                  plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar11 == (longlong *)0x0) {
LAB_23e794d18:
                    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 0xca;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e7943af;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xca;
                  plVar12 = (longlong *)FUN_23e914090(param_1,uVar7,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e794d18;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                  *(undefined4 *)(plVar3 + 5) = 0xcb;
                  plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed83a8);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e794d59;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
LAB_23e794313:
                  lVar10 = *(longlong *)_Py_FalseStruct_exref;
                  goto LAB_23e793c3e;
                }
              }
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xca;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            goto LAB_23e7943af;
          }
        }
        plVar11 = plStack_68;
        uVar7 = auStack_78._0_8_;
        uVar17 = auStack_78._8_8_;
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      uVar15 = 0xbc;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      auStack_78._8_8_ = uVar17;
      auStack_78._0_8_ = uVar7;
      plStack_68 = plVar11;
      goto LAB_23e7943af;
    }
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xb7;
    uVar15 = 0xb7;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    if (plStack_68 == (longlong *)0x0) {
      plStack_68 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      goto LAB_23e793d50;
    }
  }
  plVar12 = plStack_68;
  plVar11 = DAT_23ed6a4f8;
  if ((longlong *)plStack_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar14 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcVar14 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar16;
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar2 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
    plVar11[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plVar11;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
LAB_23e794471:
  plStack_68 = plVar12;
  FUN_23e8bba40(plVar3,&DAT_23ec5dead,plVar1,plVar8,plVar9);
  if (_DAT_23eedac60 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedac60 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar12 = plStack_68;
  plVar3[0xf] = 0;
  uVar7 = auStack_78._0_8_;
  uVar17 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  plStack_68 = plVar12;
  auStack_78._0_8_ = uVar7;
  auStack_78._8_8_ = uVar17;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return (code *)0x0;
}
