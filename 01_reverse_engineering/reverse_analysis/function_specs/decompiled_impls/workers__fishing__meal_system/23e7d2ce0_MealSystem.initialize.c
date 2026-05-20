/* ===== 23e7d2ce0 workers.fishing.meal_system:174 ===== */
/* ghidra_name=FUN_23e7d2ce0 entry=23e7d2ce0 size=6996 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7d2ce0(longlong param_1,undefined8 param_2,undefined8 *param_3)

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
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = _DAT_23eedecf0;
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (_DAT_23eedecf0 == (longlong *)0x0) {
LAB_23e7d2d37:
    _DAT_23eedecf0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedece8,DAT_23eed7940,0x18);
  }
  else {
    lVar10 = *_DAT_23eedecf0;
    if (1 < lVar10) {
      *_DAT_23eedecf0 = lVar10 + -1;
      goto LAB_23e7d2d37;
    }
    if (_DAT_23eedecf0[2] != 0) {
      *_DAT_23eedecf0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7d2d37;
    }
  }
  plVar3 = _DAT_23eedecf0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedecf0 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eedecf0[0xf] = lVar2;
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
  *(undefined4 *)(plVar3 + 5) = 0xb0;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,uRam000000023eed72f0);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0xb0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
LAB_23e7d364f:
    uVar16 = uVar15;
    if (local_68 == (longlong *)0x0) {
LAB_23e7d2fe0:
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
      if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
        (**(code **)(local_68[1] + 0x30))(local_68);
      }
      goto LAB_23e7d3711;
    }
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed72a8);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0xb1;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      goto LAB_23e7d364f;
    }
    *(undefined4 *)(plVar3 + 5) = 0xb1;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,uRam000000023eed72f8);
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
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar15 = 0xb1;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7d364f;
      }
      if (iVar6 == 0) {
        uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar3 + 5) = 0xb2;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,uRam000000023eed7300);
        if (plVar8 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar15 = 0xb2;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e7d364f;
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        lVar10 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e7d2eca:
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
        if (plVar9 == (longlong *)0x0) goto LAB_23e7d2f49;
LAB_23e7d2f39:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
LAB_23e7d2f49:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar14;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar14;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed72a8);
      if (plVar8 == (longlong *)0x0) {
LAB_23e7d3620:
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar17 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0xb6;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,uRam000000023eed7308);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e7d3620;
        plVar12 = (longlong *)FUN_23a388310(plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e7d3620;
        plVar8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar8 == (longlong *)0x0) &&
           (plVar8 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2), plVar8 == (longlong *)0x0)) {
          plVar9 = (longlong *)0x0;
        }
        else {
          plVar9 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (((plVar9 != (longlong *)0x0) ||
              (plVar9 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar9 != (longlong *)0x0))
             && (cVar5 = FUN_23a3884a0(param_1,local_78,plVar12,2), cVar5 != '\0')) {
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
            plVar11 = plRam000000023eed7310;
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
                goto LAB_23e7d3264;
              }
LAB_23e7d42c6:
              PyErr_PrintEx(0);
              Py_Exit(1);
LAB_23e7d42d9:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xc9;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7d364f;
            }
LAB_23e7d3264:
            uStack_80 = uVar17;
            local_88 = plVar8;
            lVar10 = FUN_23e94ed00(param_1,plVar13,&local_88);
            if (lVar10 == 0) {
LAB_23e7d3a38:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 0xb7;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            else {
              plVar12[4] = lVar10;
              plVar11 = plRam000000023eed7318;
              *plRam000000023eed7318 = *plRam000000023eed7318 + 1;
              plVar12[5] = (longlong)plVar11;
              uVar17 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar11 == (longlong *)0x0) goto LAB_23e7d42c6;
                *plVar11 = *plVar11 + 1;
                DAT_23ed6a4c0 = plVar11;
              }
              uStack_80 = uVar17;
              local_88 = plVar9;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
              if (lVar10 == 0) goto LAB_23e7d3a38;
              plVar12[6] = lVar10;
              plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar11 == (longlong *)0x0) {
LAB_23e7d39d0:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xb7;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7d364f;
              }
              *(undefined4 *)(plVar3 + 5) = 0xb7;
              plVar12 = (longlong *)FUN_23e914090(param_1,uVar7);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e7d39d0;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              iVar6 = FUN_23e97a530(plVar8,uRam000000023eed7320);
              if (iVar6 == -1) {
LAB_23e7d41c0:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xb9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7d364f;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,uRam000000023eed7328);
                if (iVar6 == -1) goto LAB_23e7d41c0;
                if (iVar6 != 1) goto LAB_23e7d339a;
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72b0,uRam000000023eed7330);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xba;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7338);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d4324;
                  lVar10 = *plVar12;
LAB_23e7d431b:
                  if (lVar10 == 0) goto LAB_23e7d4324;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec15628 != iVar6) {
                    _DAT_23ec15628 = iVar6;
                    _DAT_23eedecb8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7338,
                                       *(undefined8 *)(lRam000000023eed7338 + 0x18));
                  }
                  if (-1 < _DAT_23eedecb8) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedecb8 * 0x10) != 0) goto LAB_23e7d3ca7;
                    _DAT_23eedecb8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7338,
                                       *(undefined8 *)(lRam000000023eed7338 + 0x18));
                    if (-1 < _DAT_23eedecb8) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedecb8 * 0x10);
                      goto LAB_23e7d431b;
                    }
                  }
LAB_23e7d4324:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7338);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xbb;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7338);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d3ca7:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72b8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xbb;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7340);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d44f6;
                  lVar10 = *plVar12;
LAB_23e7d44ed:
                  if (lVar10 == 0) goto LAB_23e7d44f6;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec1562c != iVar6) {
                    _DAT_23ec1562c = iVar6;
                    _DAT_23eedecc0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7340,
                                       *(undefined8 *)(lRam000000023eed7340 + 0x18));
                  }
                  if (-1 < _DAT_23eedecc0) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedecc0 * 0x10) != 0) goto LAB_23e7d3d55;
                    _DAT_23eedecc0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7340,
                                       *(undefined8 *)(lRam000000023eed7340 + 0x18));
                    if (-1 < _DAT_23eedecc0) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedecc0 * 0x10);
                      goto LAB_23e7d44ed;
                    }
                  }
LAB_23e7d44f6:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7340);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xbc;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7340);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d3d55:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72c0);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xbc;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7348);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d45b6;
                  lVar10 = *plVar12;
LAB_23e7d45ad:
                  if (lVar10 == 0) goto LAB_23e7d45b6;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec15630 != iVar6) {
                    _DAT_23ec15630 = iVar6;
                    _DAT_23eedecc8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7348,
                                       *(undefined8 *)(lRam000000023eed7348 + 0x18));
                  }
                  if (-1 < _DAT_23eedecc8) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedecc8 * 0x10) != 0) goto LAB_23e7d3e03;
                    _DAT_23eedecc8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7348,
                                       *(undefined8 *)(lRam000000023eed7348 + 0x18));
                    if (-1 < _DAT_23eedecc8) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedecc8 * 0x10);
                      goto LAB_23e7d45ad;
                    }
                  }
LAB_23e7d45b6:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7348);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xbd;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7348);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d3e03:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72c8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xbd;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed7350,DAT_23ed6cd28);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar15 = 0xbe;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0xbf;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,uRam000000023eed7358);
                    if (plVar12 != (longlong *)0x0) goto LAB_23e7d3e68;
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar15 = 0xbf;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                goto LAB_23e7d364f;
              }
LAB_23e7d339a:
              iVar6 = FUN_23e97a530(plVar8,uRam000000023eed7360);
              if (iVar6 == -1) {
LAB_23e7d422e:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xc0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7d364f;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,uRam000000023eed7368);
                if (iVar6 == -1) goto LAB_23e7d422e;
                if (iVar6 != 1) goto LAB_23e7d33bb;
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72b0,uRam000000023eed7370);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc1;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7378);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d43b8;
                  lVar10 = *plVar12;
LAB_23e7d43af:
                  if (lVar10 == 0) goto LAB_23e7d43b8;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec15634 != iVar6) {
                    _DAT_23ec15634 = iVar6;
                    _DAT_23eedecd0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7378,
                                       *(undefined8 *)(lRam000000023eed7378 + 0x18));
                  }
                  if (-1 < _DAT_23eedecd0) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedecd0 * 0x10) != 0) goto LAB_23e7d3fce;
                    _DAT_23eedecd0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7378,
                                       *(undefined8 *)(lRam000000023eed7378 + 0x18));
                    if (-1 < _DAT_23eedecd0) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedecd0 * 0x10);
                      goto LAB_23e7d43af;
                    }
                  }
LAB_23e7d43b8:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7378);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xc2;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7378);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d3fce:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72b8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc2;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7380);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d448e;
                  lVar10 = *plVar12;
LAB_23e7d4485:
                  if (lVar10 == 0) goto LAB_23e7d448e;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec15638 != iVar6) {
                    _DAT_23ec15638 = iVar6;
                    _DAT_23eedecd8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7380,
                                       *(undefined8 *)(lRam000000023eed7380 + 0x18));
                  }
                  if (-1 < _DAT_23eedecd8) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedecd8 * 0x10) != 0) goto LAB_23e7d407c;
                    _DAT_23eedecd8 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7380,
                                       *(undefined8 *)(lRam000000023eed7380 + 0x18));
                    if (-1 < _DAT_23eedecd8) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedecd8 * 0x10);
                      goto LAB_23e7d4485;
                    }
                  }
LAB_23e7d448e:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7380);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xc3;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7380);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d407c:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72c0);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc3;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                lVar10 = *(longlong *)(_DAT_23eede1c0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(_DAT_23eede1c0,lRam000000023eed7388);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7d473d;
                  lVar10 = *plVar12;
LAB_23e7d4734:
                  if (lVar10 == 0) goto LAB_23e7d473d;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                    iVar6 = _DAT_23ec15654;
                    _DAT_23ec15654 = _DAT_23ec15654 + 1;
                  }
                  if (_DAT_23ec1563c != iVar6) {
                    _DAT_23ec1563c = iVar6;
                    _DAT_23eedece0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7388,
                                       *(undefined8 *)(lRam000000023eed7388 + 0x18));
                  }
                  if (-1 < _DAT_23eedece0) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedece0 * 0x10) != 0) goto LAB_23e7d412a;
                    _DAT_23eedece0 =
                         FUN_23e8cbd60(lVar10,lRam000000023eed7388,
                                       *(undefined8 *)(lRam000000023eed7388 + 0x18));
                    if (-1 < _DAT_23eedece0) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedece0 * 0x10);
                      goto LAB_23e7d4734;
                    }
                  }
LAB_23e7d473d:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7388);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar15 = 0xc4;
                    FUN_23e915740(param_1,local_78,lRam000000023eed7388);
                    goto LAB_23e7d364f;
                  }
                }
LAB_23e7d412a:
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed72c8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc4;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                cVar5 = FUN_23e8d9ac0(plVar1,uRam000000023eed7350,uRam000000023eed7390);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc5;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                *(undefined4 *)(plVar3 + 5) = 0xc6;
                plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,uRam000000023eed7398);
                if (plVar12 == (longlong *)0x0) {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0xc6;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
LAB_23e7d3e68:
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0();
                }
                *(undefined4 *)(plVar3 + 5) = 0xcd;
                plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uRam000000023eed73b0);
                if (plVar12 != (longlong *)0x0) {
                  iVar6 = FUN_23a35f020(plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  if (iVar6 != -1) {
                    if (iVar6 == 0) goto LAB_23e7d35bd;
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    pcVar14 = _Py_TrueStruct_exref;
                    *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    goto LAB_23e7d2f39;
                  }
                }
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar15 = 0xcd;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7d364f;
              }
LAB_23e7d33bb:
              uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = plRam000000023eed73a0;
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
                if (plVar13 == (longlong *)0x0) goto LAB_23e7d42c6;
                *plVar13 = *plVar13 + 1;
                DAT_23ed6a4c0 = plVar13;
              }
              uStack_80 = uVar17;
              local_88 = plVar8;
              lVar10 = FUN_23e94ed00(param_1,plVar13,&local_88);
              if (lVar10 != 0) {
                plVar12[4] = lVar10;
                plVar11 = plRam000000023eed7318;
                *plRam000000023eed7318 = *plRam000000023eed7318 + 1;
                plVar12[5] = (longlong)plVar11;
                uVar17 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar11 == (longlong *)0x0) goto LAB_23e7d42c6;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_80 = uVar17;
                local_88 = plVar9;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                if (lVar10 == 0) goto LAB_23e7d3b80;
                plVar12[6] = lVar10;
                plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (plVar11 == (longlong *)0x0) {
LAB_23e7d4298:
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 200;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d364f;
                }
                *(undefined4 *)(plVar3 + 5) = 200;
                plVar12 = (longlong *)FUN_23e914090(param_1,uVar7,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar12 == (longlong *)0x0) goto LAB_23e7d4298;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                *(undefined4 *)(plVar3 + 5) = 0xc9;
                plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,uRam000000023eed73a8);
                if (plVar12 == (longlong *)0x0) goto LAB_23e7d42d9;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
LAB_23e7d35bd:
                lVar10 = *(longlong *)_Py_FalseStruct_exref;
                goto LAB_23e7d2eca;
              }
LAB_23e7d3b80:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar15 = 200;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            goto LAB_23e7d364f;
          }
        }
        plVar11 = local_68;
        uVar7 = local_78._0_8_;
        uVar17 = local_78._8_8_;
        local_68 = (longlong *)0x0;
        local_78 = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        local_68 = (longlong *)0x0;
        local_78 = (undefined1  [16])0x0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      uVar15 = 0xb6;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      local_78._8_8_ = uVar17;
      local_78._0_8_ = uVar7;
      local_68 = plVar11;
      goto LAB_23e7d364f;
    }
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xb1;
    uVar15 = 0xb1;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    if (local_68 == (longlong *)0x0) {
      local_68 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      goto LAB_23e7d2fe0;
    }
  }
  plVar12 = local_68;
  plVar11 = DAT_23ed6a4f8;
  if ((longlong *)local_68[3] != plVar3) {
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
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))();
    }
  }
LAB_23e7d3711:
  local_68 = plVar12;
  FUN_23e8bba40(plVar3,&DAT_23ec5e2be,plVar1,plVar8,plVar9);
  if (_DAT_23eedecf0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedecf0 = (longlong *)0x0;
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
  plVar12 = local_68;
  plVar3[0xf] = 0;
  uVar7 = local_78._0_8_;
  uVar17 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  local_68 = plVar12;
  local_78._0_8_ = uVar7;
  local_78._8_8_ = uVar17;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
