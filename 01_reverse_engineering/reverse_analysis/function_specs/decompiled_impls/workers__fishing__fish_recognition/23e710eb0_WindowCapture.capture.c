/* ===== 23e710eb0 workers.fishing.fish_recognition:119 ===== */
/* ghidra_name=FUN_23e710eb0 entry=23e710eb0 size=6330 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e710eb0(longlong param_1,undefined8 param_2,undefined8 *param_3)

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
  undefined8 uVar13;
  longlong *plVar14;
  code *pcVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = _DAT_23eedb0c0;
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (_DAT_23eedb0c0 == (longlong *)0x0) {
LAB_23e710f07:
    _DAT_23eedb0c0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb0b8,DAT_23eedb148,0x18);
  }
  else {
    lVar10 = *_DAT_23eedb0c0;
    if (1 < lVar10) {
      *_DAT_23eedb0c0 = lVar10 + -1;
      goto LAB_23e710f07;
    }
    if (_DAT_23eedb0c0[2] != 0) {
      *_DAT_23eedb0c0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e710f07;
    }
  }
  plVar3 = _DAT_23eedb0c0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedb0c0 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eedb0c0[0xf] = lVar2;
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
  *(undefined4 *)(plVar3 + 5) = 0x79;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed9ec8);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x79;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
LAB_23e7117ff:
    uVar17 = uVar16;
    if (local_68 == (longlong *)0x0) {
LAB_23e7111a0:
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
      pcVar15 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar3;
      plVar12[2] = 0;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar15 + 0x1f8);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
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
      goto LAB_23e7118c1;
    }
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed9e98);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0x7a;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      goto LAB_23e7117ff;
    }
    *(undefined4 *)(plVar3 + 5) = 0x7a;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eed9ed0);
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
        uVar16 = 0x7a;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7117ff;
      }
      if (iVar6 == 0) {
        uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar3 + 5) = 0x7b;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed9ed8);
        if (plVar8 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0x7b;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e7117ff;
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        lVar10 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e71108e:
        pcVar15 = _Py_FalseStruct_exref;
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
        if (plVar9 == (longlong *)0x0) goto LAB_23e71110d;
LAB_23e7110fd:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
LAB_23e71110d:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar15;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar15;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed9e98);
      if (plVar8 == (longlong *)0x0) {
LAB_23e7117d0:
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x7f;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eed9ee0);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e7117d0;
        plVar12 = (longlong *)FUN_23a388310(plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e7117d0;
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
            plVar11 = _DAT_23eed9ee8;
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
            pcVar15 = _PyRuntime_exref;
            plVar12[6] = 0;
            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar12[-1];
            puVar4 = *(undefined8 **)(lVar10 + 8);
            *puVar4 = plVar12 + -2;
            plVar12[-2] = lVar10;
            plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar10 + 8) = plVar12 + -2;
            plVar14 = DAT_23ed6a4c0;
            *plVar11 = *plVar11 + 1;
            plVar12[3] = (longlong)plVar11;
            uVar13 = DAT_23ed6cd28;
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
                goto LAB_23e711427;
              }
LAB_23e712486:
              PyErr_PrintEx(0);
              Py_Exit(1);
LAB_23e712499:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0x8e;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7117ff;
            }
LAB_23e711427:
            uStack_80 = uVar13;
            local_88 = plVar8;
            lVar10 = FUN_23e94ed00(param_1,plVar14,&local_88);
            if (lVar10 == 0) {
LAB_23e711be8:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0x80;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            else {
              plVar12[4] = lVar10;
              plVar11 = DAT_23eed9ef0;
              *DAT_23eed9ef0 = *DAT_23eed9ef0 + 1;
              plVar12[5] = (longlong)plVar11;
              uVar13 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar11 == (longlong *)0x0) goto LAB_23e712486;
                *plVar11 = *plVar11 + 1;
                DAT_23ed6a4c0 = plVar11;
              }
              uStack_80 = uVar13;
              local_88 = plVar9;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
              if (lVar10 == 0) goto LAB_23e711be8;
              plVar12[6] = lVar10;
              plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar11 == (longlong *)0x0) {
LAB_23e711b80:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x80;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7117ff;
              }
              *(undefined4 *)(plVar3 + 5) = 0x80;
              plVar12 = (longlong *)FUN_23e914090(param_1,uVar7);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e711b80;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              iVar6 = FUN_23e97a530(plVar8,_DAT_23eed9ef8);
              if (iVar6 == -1) {
LAB_23e712380:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x82;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7117ff;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,_DAT_23eed9f00);
                if (iVar6 == -1) goto LAB_23e712380;
                if (iVar6 != 1) goto LAB_23e711553;
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed9ea0,_DAT_23eed9f08);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x83;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7117ff;
                }
                lVar10 = *(longlong *)(DAT_23eed9ce8 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eed9ce8,_DAT_23eed9f10);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e712528;
                  lVar10 = *plVar12;
LAB_23e71251f:
                  if (lVar10 == 0) goto LAB_23e712528;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = DAT_23ec15484;
                    iVar6 = DAT_23ec15484;
                    DAT_23ec15484 = DAT_23ec15484 + 1;
                  }
                  if (_DAT_23ec1546c != iVar6) {
                    _DAT_23ec1546c = iVar6;
                    _DAT_23eedb0a8 =
                         FUN_23e8cbd60(lVar10,_DAT_23eed9f10,*(undefined8 *)(_DAT_23eed9f10 + 0x18))
                    ;
                  }
                  if (-1 < _DAT_23eedb0a8) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedb0a8 * 0x10) != 0) goto LAB_23e711e3d;
                    _DAT_23eedb0a8 =
                         FUN_23e8cbd60(lVar10,_DAT_23eed9f10,*(undefined8 *)(_DAT_23eed9f10 + 0x18))
                    ;
                    if (-1 < _DAT_23eedb0a8) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedb0a8 * 0x10);
                      goto LAB_23e71251f;
                    }
                  }
LAB_23e712528:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9f10);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar16 = 0x84;
                    FUN_23e915740(param_1,local_78,_DAT_23eed9f10);
                    goto LAB_23e7117ff;
                  }
                }
LAB_23e711e3d:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed9ea8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x84;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed9f20,_DAT_23eed9f18);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar16 = 0x85;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0x86;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed9f28);
                    if (plVar12 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar16 = 0x86;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
LAB_23e711ea3:
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
                      plVar12 = _DAT_23eed9f70;
                      plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),8);
                      *plVar12 = *plVar12 + 1;
                      uVar7 = DAT_23eed9ea8;
                      plVar11[3] = (longlong)plVar12;
                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                      if (plVar12 == (longlong *)0x0) {
LAB_23e7124c7:
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar16 = 0x91;
                      }
                      else {
                        plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9ef0);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e7124c7;
                        lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        plVar12 = DAT_23eed9f78;
                        if (lVar10 == 0) goto LAB_23e7124c7;
                        plVar11[4] = lVar10;
                        uVar7 = DAT_23eed9ea8;
                        *plVar12 = *plVar12 + 1;
                        plVar11[5] = (longlong)plVar12;
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                        if (plVar12 == (longlong *)0x0) goto LAB_23e7124c7;
                        plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9f80);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e7124c7;
                        lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        plVar12 = _DAT_23eed9f88;
                        if (lVar10 == 0) goto LAB_23e7124c7;
                        plVar11[6] = lVar10;
                        uVar7 = DAT_23eed9ea8;
                        *plVar12 = *plVar12 + 1;
                        plVar11[7] = (longlong)plVar12;
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                        if (plVar12 != (longlong *)0x0) {
                          plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9f90);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar14 != (longlong *)0x0) {
                            lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0();
                            }
                            plVar12 = _DAT_23eed9f98;
                            if (lVar10 != 0) {
                              plVar11[8] = lVar10;
                              uVar7 = DAT_23eed9ea8;
                              *plVar12 = *plVar12 + 1;
                              plVar11[9] = (longlong)plVar12;
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                              if (plVar12 != (longlong *)0x0) {
                                plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eed9fa0);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  uVar7 = DAT_23ed6cd28;
                                  if (lVar10 != 0) {
                                    plVar11[10] = lVar10;
                                    plVar12 = (longlong *)PyUnicode_Join(uVar7);
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      FUN_23a334bc0(plVar11);
                                    }
                                    if (plVar12 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar3 + 5) = 0x91;
                                      plVar11 = (longlong *)FUN_23e914090(param_1,uVar13,plVar12);
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        FUN_23a334bc0(plVar12);
                                      }
                                      if (plVar11 != (longlong *)0x0) {
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          FUN_23a334bc0(plVar11);
                                        }
                                        *(undefined4 *)(plVar3 + 5) = 0x95;
                                        plVar12 = (longlong *)
                                                  FUN_23e91bfe0(param_1,plVar1,_DAT_23eed9fa8);
                                        if (plVar12 != (longlong *)0x0) {
                                          iVar6 = FUN_23a35f020(plVar12);
                                          *plVar12 = *plVar12 + -1;
                                          if (*plVar12 == 0) {
                                            FUN_23a334bc0(plVar12);
                                          }
                                          if (iVar6 != -1) {
                                            if (iVar6 == 0) goto LAB_23e711763;
                                            FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                            pcVar15 = _Py_TrueStruct_exref;
                                            *(longlong *)_Py_TrueStruct_exref =
                                                 *(longlong *)_Py_TrueStruct_exref + 1;
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                                            }
                                            goto LAB_23e7110fd;
                                          }
                                        }
                                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                        local_68 = *(longlong **)(param_1 + 0x70);
                                        uVar16 = 0x95;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e7117ff;
                                      }
                                    }
                                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_68 = *(longlong **)(param_1 + 0x70);
                                    uVar16 = 0x91;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e7117ff;
                                  }
                                }
                              }
                            }
                          }
                        }
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar16 = 0x92;
                      }
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                    }
                  }
                }
                goto LAB_23e7117ff;
              }
LAB_23e711553:
              iVar6 = FUN_23e97a530(plVar8,_DAT_23eed9f30);
              if (iVar6 == -1) {
LAB_23e7123ee:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x87;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e7117ff;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,_DAT_23eed9f38);
                if (iVar6 == -1) goto LAB_23e7123ee;
                if (iVar6 != 1) goto LAB_23e711574;
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed9ea0,_DAT_23eed9f40);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x88;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7117ff;
                }
                lVar10 = *(longlong *)(DAT_23eed9ce8 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eed9ce8,_DAT_23eed9f48);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e7125e9;
                  lVar10 = *plVar12;
LAB_23e7125e0:
                  if (lVar10 == 0) goto LAB_23e7125e9;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = DAT_23ec15484;
                    iVar6 = DAT_23ec15484;
                    DAT_23ec15484 = DAT_23ec15484 + 1;
                  }
                  if (_DAT_23ec15470 != iVar6) {
                    _DAT_23ec15470 = iVar6;
                    _DAT_23eedb0b0 =
                         FUN_23e8cbd60(lVar10,_DAT_23eed9f48,*(undefined8 *)(_DAT_23eed9f48 + 0x18))
                    ;
                  }
                  if (-1 < _DAT_23eedb0b0) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + _DAT_23eedb0b0 * 0x10) != 0) goto LAB_23e7122e4;
                    _DAT_23eedb0b0 =
                         FUN_23e8cbd60(lVar10,_DAT_23eed9f48,*(undefined8 *)(_DAT_23eed9f48 + 0x18))
                    ;
                    if (-1 < _DAT_23eedb0b0) {
                      lVar10 = *(longlong *)(lVar2 + 8 + _DAT_23eedb0b0 * 0x10);
                      goto LAB_23e7125e0;
                    }
                  }
LAB_23e7125e9:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9f48);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar16 = 0x89;
                    FUN_23e915740(param_1,local_78,_DAT_23eed9f48);
                    goto LAB_23e7117ff;
                  }
                }
LAB_23e7122e4:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eed9ea8);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x89;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,_DAT_23eed9f20,_DAT_23eed9f50);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x8a;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0x8b;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7);
                    if (plVar12 != (longlong *)0x0) goto LAB_23e711ea3;
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x8b;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                goto LAB_23e7117ff;
              }
LAB_23e711574:
              uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = _DAT_23eed9f60;
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
              pcVar15 = _PyRuntime_exref;
              plVar12[6] = 0;
              *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
              lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
              lVar2 = plVar12[-1];
              puVar4 = *(undefined8 **)(lVar10 + 8);
              *puVar4 = plVar12 + -2;
              plVar12[-2] = lVar10;
              plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
              *(longlong **)(lVar10 + 8) = plVar12 + -2;
              plVar14 = DAT_23ed6a4c0;
              *plVar11 = *plVar11 + 1;
              plVar12[3] = (longlong)plVar11;
              uVar13 = DAT_23ed6cd28;
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar14 == (longlong *)0x0) goto LAB_23e712486;
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              uStack_80 = uVar13;
              local_88 = plVar8;
              lVar10 = FUN_23e94ed00(param_1,plVar14,&local_88);
              if (lVar10 != 0) {
                plVar12[4] = lVar10;
                plVar11 = DAT_23eed9ef0;
                *DAT_23eed9ef0 = *DAT_23eed9ef0 + 1;
                plVar12[5] = (longlong)plVar11;
                uVar13 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar11 == (longlong *)0x0) goto LAB_23e712486;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_80 = uVar13;
                local_88 = plVar9;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                if (lVar10 != 0) {
                  plVar12[6] = lVar10;
                  plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar11 == (longlong *)0x0) {
LAB_23e712458:
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x8d;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e7117ff;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x8d;
                  plVar12 = (longlong *)FUN_23e914090(param_1,uVar7,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e712458;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                  *(undefined4 *)(plVar3 + 5) = 0x8e;
                  plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,_DAT_23eed9f68);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e712499;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
LAB_23e711763:
                  lVar10 = *(longlong *)_Py_FalseStruct_exref;
                  goto LAB_23e71108e;
                }
              }
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0x8d;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            goto LAB_23e7117ff;
          }
        }
        plVar11 = local_68;
        uVar7 = local_78._0_8_;
        uVar13 = local_78._8_8_;
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
      uVar16 = 0x7f;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      local_78._8_8_ = uVar13;
      local_78._0_8_ = uVar7;
      local_68 = plVar11;
      goto LAB_23e7117ff;
    }
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0x7a;
    uVar16 = 0x7a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    if (local_68 == (longlong *)0x0) {
      local_68 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      goto LAB_23e7111a0;
    }
  }
  plVar12 = local_68;
  plVar11 = DAT_23ed6a4f8;
  if ((longlong *)local_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar17;
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
LAB_23e7118c1:
  local_68 = plVar12;
  FUN_23e8bba40(plVar3,&DAT_23ec5dead,plVar1,plVar8,plVar9);
  if (_DAT_23eedb0c0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedb0c0 = (longlong *)0x0;
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
  uVar13 = local_78._8_8_;
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
  local_78._8_8_ = uVar13;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
