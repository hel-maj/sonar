/* ===== 23e848360 workers.fishing.window_activator:? ===== */
/* ghidra_name=FUN_23e848360 entry=23e848360 size=48864 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e848360(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  undefined8 uVar22;
  longlong *plVar23;
  longlong **pplVar24;
  longlong **pplVar25;
  longlong **pplVar26;
  longlong **pplVar27;
  undefined8 uVar28;
  longlong *plVar29;
  code *pcVar30;
  longlong **pplVar31;
  undefined1 auVar32 [8];
  undefined *puVar33;
  longlong lVar34;
  undefined4 uVar35;
  longlong *local_280;
  longlong *local_278;
  longlong *local_270;
  code *local_268;
  longlong *local_260;
  longlong *local_258;
  longlong *local_250;
  longlong *local_248;
  longlong *local_240;
  longlong *local_238;
  longlong *local_230;
  longlong *local_228;
  longlong *local_220;
  undefined *local_208;
  longlong *local_200;
  longlong *local_1f8;
  undefined1 local_1b8 [16];
  longlong **local_1a8 [2];
  longlong **local_198;
  longlong **pplStack_190;
  longlong **local_188;
  longlong **local_178;
  longlong **pplStack_170;
  longlong **local_168;
  longlong **local_158;
  longlong **pplStack_150;
  longlong **local_148;
  longlong **local_138;
  longlong **pplStack_130;
  longlong **local_128;
  longlong **local_118;
  longlong **pplStack_110;
  longlong **local_108;
  undefined1 local_f8 [16];
  longlong **local_e8 [2];
  longlong **local_d8;
  longlong **pplStack_d0;
  longlong **local_c8;
  undefined1 local_b8 [8];
  longlong **pplStack_b0;
  longlong **local_a8 [2];
  longlong *local_98;
  code *pcStack_90;
  code *local_88;
  code *pcStack_80;
  longlong *local_78;
  
  plVar10 = DAT_23eede370;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_a8[0] = (longlong **)0x0;
  local_b8 = (undefined1  [8])0x0;
  pplStack_b0 = (longlong **)0x0;
  if (DAT_23eede370 == (longlong *)0x0) {
LAB_23e8483db:
    DAT_23eede370 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede368,DAT_23eede398,0x78);
  }
  else {
    lVar9 = *DAT_23eede370;
    if (1 < lVar9) {
      *DAT_23eede370 = lVar9 + -1;
      goto LAB_23e8483db;
    }
    if (DAT_23eede370[2] != 0) {
      *DAT_23eede370 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e8483db;
    }
  }
  plVar3 = DAT_23eede370;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar10 = DAT_23eede370 + 9;
  lVar16 = *(longlong *)(lVar9 + 8);
  DAT_23eede370[0xf] = lVar16;
  *(longlong **)(lVar9 + 8) = plVar10;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  iVar7 = FUN_23a35f020();
  if (iVar7 == -1) {
LAB_23e849b80:
    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
    local_a8[0] = *(longlong ***)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_a8[0] == (longlong **)0x0) {
LAB_23e84b040:
      local_240 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar7 = 0x4e;
      local_258 = (longlong *)0x0;
      local_230 = (longlong *)0x0;
      local_238 = (longlong *)0x0;
      local_250 = (longlong *)0x0;
      local_270 = (longlong *)0x0;
      local_248 = (longlong *)0x0;
      local_268 = (code *)0x0;
      local_278 = (longlong *)0x0;
      local_260 = (longlong *)0x0;
      local_280 = (longlong *)0x0;
      goto LAB_23e84b0cc;
    }
    if (local_a8[0][3] == plVar3) {
LAB_23e84aa00:
      local_240 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_258 = (longlong *)0x0;
      local_230 = (longlong *)0x0;
      local_238 = (longlong *)0x0;
      local_250 = (longlong *)0x0;
      local_270 = (longlong *)0x0;
      local_248 = (longlong *)0x0;
      local_268 = (code *)0x0;
      local_278 = (longlong *)0x0;
      local_260 = (longlong *)0x0;
      local_280 = (longlong *)0x0;
      pplVar25 = local_a8[0];
      goto LAB_23e849cf0;
    }
    local_240 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar7 = 0x4e;
    local_258 = (longlong *)0x0;
    local_230 = (longlong *)0x0;
    local_238 = (longlong *)0x0;
    local_250 = (longlong *)0x0;
    local_270 = (longlong *)0x0;
    local_248 = (longlong *)0x0;
    local_268 = (code *)0x0;
    local_278 = (longlong *)0x0;
    local_260 = (longlong *)0x0;
    local_280 = (longlong *)0x0;
LAB_23e849c4a:
    pplVar24 = local_a8[0];
    pplVar25 = (longlong **)DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pplVar25 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar15 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    pplVar25[3] = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)(pplVar25 + 4) = 0xffffffff;
    *(int *)((longlong)pplVar25 + 0x24) = iVar7;
    plVar11 = *(longlong **)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    plVar13 = pplVar25[-1];
    puVar5 = (undefined8 *)plVar11[1];
    *puVar5 = pplVar25 + -2;
    pplVar25[-2] = plVar11;
    pplVar25[-1] = (longlong *)((ulonglong)((uint)plVar13 & 3) | (ulonglong)puVar5);
    plVar11[1] = (longlong)(pplVar25 + -2);
    pplVar25[2] = (longlong *)pplVar24;
    *pplVar24 = (longlong *)((longlong)*pplVar24 + 1);
    pplVar24 = local_a8[0];
  }
  else {
    if (iVar7 == 0) {
LAB_23e848482:
      pcVar15 = _Py_FalseStruct_exref;
      plVar10 = (longlong *)0x0;
      local_240 = (longlong *)0x0;
      local_258 = (longlong *)0x0;
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      local_230 = (longlong *)0x0;
      local_238 = (longlong *)0x0;
      local_250 = (longlong *)0x0;
      local_270 = (longlong *)0x0;
      local_248 = (longlong *)0x0;
      local_268 = (code *)0x0;
      local_278 = (longlong *)0x0;
      local_260 = (longlong *)0x0;
      local_280 = (longlong *)0x0;
LAB_23e848513:
      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar3 = *(longlong **)(lVar9 + 0x28);
      plVar11 = (longlong *)plVar3[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
      *(undefined4 *)(plVar3 + 8) = 0xffffffff;
      if (plVar11 != (longlong *)0x0) {
        plVar3[2] = 0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      plVar3[0xf] = 0;
LAB_23e84855e:
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((local_280 != (longlong *)0x0) &&
         (lVar9 = *local_280, *local_280 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_280[1] + 0x30))(local_280);
      }
      if ((local_260 != (longlong *)0x0) &&
         (lVar9 = *local_260, *local_260 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_260[1] + 0x30))(local_260);
      }
      if ((local_278 != (longlong *)0x0) &&
         (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_278[1] + 0x30))(local_278);
      }
      if ((local_268 != (code *)0x0) &&
         (lVar9 = *(longlong *)local_268, *(longlong *)local_268 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(*(longlong *)(local_268 + 8) + 0x30))(local_268);
      }
      if ((local_248 != (longlong *)0x0) &&
         (lVar9 = *local_248, *local_248 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_248[1] + 0x30))(local_248);
      }
      if ((local_270 != (longlong *)0x0) &&
         (lVar9 = *local_270, *local_270 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_270[1] + 0x30))(local_270);
      }
      if ((local_250 != (longlong *)0x0) &&
         (lVar9 = *local_250, *local_250 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_250[1] + 0x30))(local_250);
      }
      if ((local_238 != (longlong *)0x0) &&
         (lVar9 = *local_238, *local_238 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_238[1] + 0x30))(local_238);
      }
      if ((local_230 != (longlong *)0x0) &&
         (lVar9 = *local_230, *local_230 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_230[1] + 0x30))(local_230);
      }
      if ((local_258 != (longlong *)0x0) &&
         (lVar9 = *local_258, *local_258 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_258[1] + 0x30))(local_258);
      }
      if ((local_240 != (longlong *)0x0) &&
         (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_240[1] + 0x30))(local_240);
      }
      lVar9 = *plVar1;
      *plVar1 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      lVar9 = *plVar2;
      *plVar2 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar15;
      }
      return pcVar15;
    }
    lVar9 = FUN_23e8daec0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
joined_r0x00023e84b032:
      if (local_a8[0] != (longlong **)0x0) {
        plVar10 = (longlong *)0x0;
        if (local_a8[0][3] != plVar3) {
          local_240 = (longlong *)0x0;
          iVar7 = 0x4e;
          local_258 = (longlong *)0x0;
          local_230 = (longlong *)0x0;
          local_238 = (longlong *)0x0;
          local_250 = (longlong *)0x0;
          local_270 = (longlong *)0x0;
          local_248 = (longlong *)0x0;
          local_268 = (code *)0x0;
          local_278 = (longlong *)0x0;
          local_260 = (longlong *)0x0;
          local_280 = (longlong *)0x0;
          goto LAB_23e849c4a;
        }
        goto LAB_23e84aa00;
      }
      goto LAB_23e84b040;
    }
    *(undefined4 *)(plVar3 + 5) = 0x4e;
    plVar10 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23eedbbe8);
    if (plVar10 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      local_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto joined_r0x00023e84b032;
    }
    uVar8 = FUN_23a35f020();
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    if (uVar8 == 0xffffffff) goto LAB_23e849b80;
    if ((uVar8 & 1) == 0) goto LAB_23e848482;
    plVar10 = (longlong *)FUN_23e9834c0(param_1,plVar2);
    if (plVar10 == (longlong *)0x0) {
      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
      local_a8[0] = *(longlong ***)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_a8[0] != (longlong **)0x0) {
        if (local_a8[0][3] != plVar3) {
          local_240 = (longlong *)0x0;
          iVar7 = 0x51;
          local_258 = (longlong *)0x0;
          local_230 = (longlong *)0x0;
          local_238 = (longlong *)0x0;
          local_250 = (longlong *)0x0;
          local_270 = (longlong *)0x0;
          local_248 = (longlong *)0x0;
          local_268 = (code *)0x0;
          local_278 = (longlong *)0x0;
          local_260 = (longlong *)0x0;
          local_280 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          goto LAB_23e849c4a;
        }
        goto LAB_23e84aa00;
      }
LAB_23e84d3f0:
      local_240 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar7 = 0x51;
      local_258 = (longlong *)0x0;
      local_230 = (longlong *)0x0;
      local_238 = (longlong *)0x0;
      local_250 = (longlong *)0x0;
      local_270 = (longlong *)0x0;
      local_248 = (longlong *)0x0;
      local_268 = (code *)0x0;
      local_278 = (longlong *)0x0;
      local_260 = (longlong *)0x0;
      local_280 = (longlong *)0x0;
    }
    else {
      plVar11 = (longlong *)FUN_23ebf7180();
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      if (plVar11 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        local_a8[0] = *(longlong ***)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8[0] != (longlong **)0x0) {
          if (local_a8[0][3] != plVar3) {
            local_240 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            iVar7 = 0x51;
            local_258 = (longlong *)0x0;
            local_230 = (longlong *)0x0;
            local_238 = (longlong *)0x0;
            local_250 = (longlong *)0x0;
            local_270 = (longlong *)0x0;
            local_248 = (longlong *)0x0;
            local_268 = (code *)0x0;
            local_278 = (longlong *)0x0;
            local_260 = (longlong *)0x0;
            local_280 = (longlong *)0x0;
            goto LAB_23e849c4a;
          }
          goto LAB_23e84aa00;
        }
        goto LAB_23e84d3f0;
      }
      if (plVar2 != (longlong *)0x0) {
        local_208 = (undefined *)0x0;
        plVar10 = (longlong *)0x0;
        local_240 = (longlong *)0x0;
        local_258 = (longlong *)0x0;
        local_230 = (longlong *)0x0;
        local_238 = (longlong *)0x0;
        local_250 = (longlong *)0x0;
        local_270 = (longlong *)0x0;
        local_248 = (longlong *)0x0;
        local_268 = (code *)0x0;
        local_278 = (longlong *)0x0;
        local_260 = (longlong *)0x0;
        local_280 = (longlong *)0x0;
        goto LAB_23e84895a;
      }
      plVar10 = (longlong *)(**(code **)(plVar11[1] + 0xe0))();
      if (plVar10 == (longlong *)0x0) {
        cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar6 == '\0') {
          auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
          pplVar26 = *(longlong ***)(param_1 + 0x68);
          pplVar25 = *(longlong ***)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_240 = (longlong *)0x0;
          local_258 = (longlong *)0x0;
          local_230 = (longlong *)0x0;
          local_238 = (longlong *)0x0;
          local_250 = (longlong *)0x0;
          local_270 = (longlong *)0x0;
          local_248 = (longlong *)0x0;
          local_268 = (code *)0x0;
          local_278 = (longlong *)0x0;
          local_260 = (longlong *)0x0;
          local_280 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar12 = plVar10;
LAB_23e84cdc0:
          plVar10 = plVar12;
          local_a8[0] = (longlong **)0x0;
          _local_b8 = (undefined1  [16])0x0;
          iVar7 = 0x51;
          goto LAB_23e84a761;
        }
        plVar10 = (longlong *)0x0;
        local_258 = (longlong *)0x0;
        local_240 = (longlong *)0x0;
        local_278 = (longlong *)0x0;
        local_260 = (longlong *)0x0;
        local_248 = (longlong *)0x0;
        local_270 = (longlong *)0x0;
        local_230 = (longlong *)0x0;
        local_238 = (longlong *)0x0;
        local_250 = (longlong *)0x0;
        local_280 = (longlong *)0x0;
        local_268 = (code *)0x0;
LAB_23e84c9cf:
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        uVar28 = FUN_23a3a0d40(DAT_23ed6cf28);
        uVar22 = DAT_23eedbdb8;
        *(undefined4 *)(plVar3 + 5) = 0xf5;
        plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar28,uVar22);
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar3 = *(longlong **)(lVar9 + 0x28);
          plVar11 = (longlong *)plVar3[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
          *(undefined4 *)(plVar3 + 8) = 0xffffffff;
          if (plVar11 != (longlong *)0x0) {
            plVar3[2] = 0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))();
            }
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))(plVar3);
          }
          plVar3[0xf] = 0;
          pcVar15 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          goto LAB_23e84855e;
        }
        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
        local_a8[0] = *(longlong ***)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8[0] != (longlong **)0x0) {
          iVar7 = 0xf5;
          pplVar25 = local_a8[0];
          if (plVar3 == local_a8[0][3]) goto LAB_23e849cf0;
          goto LAB_23e849c4a;
        }
        iVar7 = 0xf5;
      }
      else {
        *plVar10 = *plVar10 + 1;
        lVar9 = FUN_23e8daec0();
        if (lVar9 == 0) {
          FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
          pplVar25 = (longlong **)_Py_NoneStruct_exref;
LAB_23e84ccd7:
          local_240 = (longlong *)0x0;
          iVar7 = 0x58;
          local_258 = (longlong *)0x0;
          local_230 = (longlong *)0x0;
          local_238 = (longlong *)0x0;
          local_250 = (longlong *)0x0;
          local_270 = (longlong *)0x0;
          local_248 = (longlong *)0x0;
          local_268 = (code *)0x0;
          local_278 = (longlong *)0x0;
          local_260 = (longlong *)0x0;
          local_280 = (longlong *)0x0;
        }
        else {
          plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbf0);
          if (plVar13 == (longlong *)0x0) {
LAB_23e84cca5:
            local_a8[0] = *(longlong ***)(param_1 + 0x70);
            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pplVar25 = (longlong **)_Py_NoneStruct_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e84ccd7;
          }
          if (plVar1 == (longlong *)0x0) {
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            pplStack_b0 = (longlong **)
                          PyUnicode_FromFormat
                                    ("cannot access local variable \'%U\' where it is not associated with a value"
                                     ,DAT_23eedbbf8);
            pplVar25 = (longlong **)_Py_NoneStruct_exref;
            local_b8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
            *(longlong **)local_b8 = (longlong *)((longlong)*(longlong **)local_b8 + 1);
            local_a8[0] = (longlong **)0x0;
            if (local_b8 != (undefined1  [8])pplVar25) {
              FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
            }
            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pplStack_b0);
            goto LAB_23e84ccd7;
          }
          *(undefined4 *)(plVar3 + 5) = 0x58;
          plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if (plVar14 == (longlong *)0x0) goto LAB_23e84cca5;
          iVar7 = FUN_23a35f020();
          lVar9 = *plVar14 + -1;
          if (iVar7 == -1) {
            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            local_a8[0] = *(longlong ***)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar14 = lVar9;
            if (lVar9 != 0) {
              iVar7 = 0x58;
              local_240 = (longlong *)0x0;
              local_258 = (longlong *)0x0;
              local_230 = (longlong *)0x0;
              local_238 = (longlong *)0x0;
              local_250 = (longlong *)0x0;
              local_270 = (longlong *)0x0;
              local_248 = (longlong *)0x0;
              local_268 = (code *)0x0;
              local_278 = (longlong *)0x0;
              local_260 = (longlong *)0x0;
              local_280 = (longlong *)0x0;
              pplVar25 = (longlong **)_Py_NoneStruct_exref;
              goto LAB_23e84c550;
            }
            (**(code **)(plVar14[1] + 0x30))();
            pplVar25 = (longlong **)_Py_NoneStruct_exref;
            goto LAB_23e84ccd7;
          }
          *plVar14 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar7 != 0) {
            lVar9 = FUN_23e8daec0();
            if (lVar9 == 0) {
              FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
            }
            else {
              plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc00);
              pplVar25 = (longlong **)_Py_NoneStruct_exref;
              if (plVar13 == (longlong *)0x0) {
                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                iVar7 = 0x59;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_240 = (longlong *)0x0;
                local_258 = (longlong *)0x0;
                local_230 = (longlong *)0x0;
                local_238 = (longlong *)0x0;
                local_250 = (longlong *)0x0;
                local_270 = (longlong *)0x0;
                local_248 = (longlong *)0x0;
                local_268 = (code *)0x0;
                local_278 = (longlong *)0x0;
                local_260 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_280 = (longlong *)0x0;
                goto LAB_23e84c550;
              }
              lVar9 = FUN_23e8dad70();
              if (lVar9 == 0) {
                FUN_23e915740(param_1,local_b8,DAT_23eedbc08);
              }
              else {
                pcVar15 = (code *)FUN_23e8bc2f0(lVar9,DAT_23eedbc10);
                if (pcVar15 != (code *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0x59;
                  local_98 = plVar1;
                  pcStack_90 = pcVar15;
                  plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
                  lVar9 = *plVar13;
                  *plVar13 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
                  }
                  if (plVar14 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84e8eb;
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  lVar9 = FUN_23e8dac20();
                  uVar22 = DAT_23eedbc20;
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x5a;
                    plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,uVar22);
                    if (plVar13 != (longlong *)0x0) {
                      lVar9 = *plVar13;
                      *plVar13 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      goto LAB_23e84b3fd;
                    }
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  local_280 = (longlong *)0x0;
                  iVar7 = 0x5a;
                  local_240 = (longlong *)0x0;
                  local_258 = (longlong *)0x0;
                  local_230 = (longlong *)0x0;
                  local_238 = (longlong *)0x0;
                  local_250 = (longlong *)0x0;
                  local_270 = (longlong *)0x0;
                  local_248 = (longlong *)0x0;
                  local_268 = (code *)0x0;
                  local_278 = (longlong *)0x0;
                  local_260 = (longlong *)0x0;
                  pplVar25 = (longlong **)_Py_NoneStruct_exref;
                  goto LAB_23e84c550;
                }
                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              lVar9 = *plVar13;
              *plVar13 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
            }
LAB_23e84e8eb:
            iVar7 = 0x59;
            local_240 = (longlong *)0x0;
            local_258 = (longlong *)0x0;
            local_230 = (longlong *)0x0;
            local_238 = (longlong *)0x0;
            local_250 = (longlong *)0x0;
            local_270 = (longlong *)0x0;
            local_248 = (longlong *)0x0;
            local_268 = (code *)0x0;
            local_278 = (longlong *)0x0;
            local_260 = (longlong *)0x0;
            local_280 = (longlong *)0x0;
            pplVar25 = (longlong **)_Py_NoneStruct_exref;
            goto LAB_23e84c550;
          }
LAB_23e84b3fd:
          lVar9 = FUN_23e8daec0();
          if (lVar9 == 0) {
            FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e84e2b7:
            local_240 = (longlong *)0x0;
            iVar7 = 0x5d;
            local_258 = (longlong *)0x0;
            local_230 = (longlong *)0x0;
            local_238 = (longlong *)0x0;
            local_250 = (longlong *)0x0;
            local_270 = (longlong *)0x0;
            local_248 = (longlong *)0x0;
            local_268 = (code *)0x0;
            local_278 = (longlong *)0x0;
            local_260 = (longlong *)0x0;
            local_280 = (longlong *)0x0;
            pplVar25 = (longlong **)_Py_NoneStruct_exref;
          }
          else {
            plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc00);
            if (plVar13 == (longlong *)0x0) {
              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
              local_a8[0] = *(longlong ***)(param_1 + 0x70);
              iVar7 = 0x5d;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pplVar25 = (longlong **)_Py_NoneStruct_exref;
              local_240 = (longlong *)0x0;
              local_258 = (longlong *)0x0;
              local_230 = (longlong *)0x0;
              local_238 = (longlong *)0x0;
              local_250 = (longlong *)0x0;
              local_270 = (longlong *)0x0;
              local_248 = (longlong *)0x0;
              local_268 = (code *)0x0;
              local_278 = (longlong *)0x0;
              local_260 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              local_280 = (longlong *)0x0;
              goto LAB_23e84c550;
            }
            lVar9 = FUN_23e8dad70();
            if (lVar9 == 0) {
              FUN_23e915740(param_1,local_b8,DAT_23eedbc08);
LAB_23e84e291:
              lVar9 = *plVar13;
              *plVar13 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              goto LAB_23e84e2b7;
            }
            pcVar15 = (code *)FUN_23e8bc2f0(lVar9,DAT_23eedbc30);
            if (pcVar15 == (code *)0x0) {
              local_a8[0] = *(longlong ***)(param_1 + 0x70);
              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e84e291;
            }
            *(undefined4 *)(plVar3 + 5) = 0x5d;
            local_98 = plVar1;
            pcStack_90 = pcVar15;
            plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
            lVar9 = *plVar13;
            *plVar13 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
            if (*(longlong *)pcVar15 == 0) {
              (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
            }
            if (plVar14 == (longlong *)0x0) {
              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
              local_a8[0] = *(longlong ***)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e84e2b7;
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            lVar16 = FUN_23e8dac20();
            lVar9 = DAT_23eedbc38;
            uVar22 = DAT_23eedbc20;
            if (lVar16 == 0) {
              FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
LAB_23e84ed53:
              local_280 = (longlong *)0x0;
              iVar7 = 0x5e;
              local_240 = (longlong *)0x0;
              local_258 = (longlong *)0x0;
              local_230 = (longlong *)0x0;
              local_238 = (longlong *)0x0;
              local_250 = (longlong *)0x0;
              local_270 = (longlong *)0x0;
              local_248 = (longlong *)0x0;
              local_268 = (code *)0x0;
              local_278 = (longlong *)0x0;
              local_260 = (longlong *)0x0;
              pplVar25 = (longlong **)_Py_NoneStruct_exref;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x5e;
              plVar13 = (longlong *)
                        FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
              if (plVar13 == (longlong *)0x0) {
                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e84ed53;
              }
              lVar9 = *plVar13;
              *plVar13 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              lVar9 = FUN_23e8daec0();
              if (lVar9 == 0) {
                FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e84edce:
                iVar7 = 0x61;
                local_240 = (longlong *)0x0;
                local_258 = (longlong *)0x0;
                local_230 = (longlong *)0x0;
                local_238 = (longlong *)0x0;
                local_250 = (longlong *)0x0;
                local_270 = (longlong *)0x0;
                local_248 = (longlong *)0x0;
                local_268 = (code *)0x0;
                local_278 = (longlong *)0x0;
                local_260 = (longlong *)0x0;
                local_280 = (longlong *)0x0;
                pplVar25 = (longlong **)_Py_NoneStruct_exref;
                goto LAB_23e84c550;
              }
              plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc40);
              pplVar25 = (longlong **)_Py_NoneStruct_exref;
              if (plVar13 == (longlong *)0x0) {
                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                iVar7 = 0x61;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_240 = (longlong *)0x0;
                local_258 = (longlong *)0x0;
                local_230 = (longlong *)0x0;
                local_238 = (longlong *)0x0;
                local_250 = (longlong *)0x0;
                local_270 = (longlong *)0x0;
                local_248 = (longlong *)0x0;
                local_268 = (code *)0x0;
                local_278 = (longlong *)0x0;
                local_260 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_280 = (longlong *)0x0;
                goto LAB_23e84c550;
              }
              *(undefined4 *)(plVar3 + 5) = 0x61;
              plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
              lVar9 = *plVar13;
              *plVar13 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              if (plVar14 == (longlong *)0x0) {
                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e84edce;
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              lVar9 = FUN_23e8dac20();
              uVar22 = DAT_23eedbc20;
              if (lVar9 == 0) {
                FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
LAB_23e84f958:
                local_280 = (longlong *)0x0;
                iVar7 = 0x62;
                local_240 = (longlong *)0x0;
                local_258 = (longlong *)0x0;
                local_230 = (longlong *)0x0;
                local_238 = (longlong *)0x0;
                local_250 = (longlong *)0x0;
                local_270 = (longlong *)0x0;
                local_248 = (longlong *)0x0;
                local_268 = (code *)0x0;
                local_278 = (longlong *)0x0;
                local_260 = (longlong *)0x0;
                pplVar25 = (longlong **)_Py_NoneStruct_exref;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x62;
                plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,uVar22);
                if (plVar13 == (longlong *)0x0) {
                  local_a8[0] = *(longlong ***)(param_1 + 0x70);
                  local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e84f958;
                }
                lVar9 = *plVar13;
                *plVar13 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                lVar9 = FUN_23e8daec0();
                if (lVar9 == 0) {
                  FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e854283:
                  uVar35 = 0x6b;
                  local_248 = (longlong *)0x0;
                  local_268 = (code *)0x0;
                  local_278 = (longlong *)0x0;
                  local_260 = (longlong *)0x0;
                  local_280 = (longlong *)0x0;
LAB_23e84f535:
                  pplVar25 = local_a8[0];
                  local_a8[0] = (longlong **)0x0;
                  local_e8[0] = pplVar25;
                  plVar13 = *(longlong **)(param_1 + 0x138);
                  local_f8._8_8_ = pplStack_b0;
                  local_f8._0_8_ = local_b8;
                  local_b8 = (undefined1  [8])0x0;
                  pplStack_b0 = (longlong **)0x0;
                  if (plVar13 != (longlong *)0x0) {
                    *plVar13 = *plVar13 + 1;
                  }
                  pplVar24 = (longlong **)DAT_23ed6a4f8;
                  if (pplVar25 == (longlong **)0x0) {
                    if (DAT_23ed6a4f8 == (code *)0x0) {
                      pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      pcVar15 = *(code **)DAT_23ed6a4f8;
                      *(undefined8 *)DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = pcVar15;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    pcVar15 = _PyRuntime_exref;
                    pplVar24[3] = plVar3;
                    pplVar24[2] = (longlong *)0x0;
                    *plVar3 = *plVar3 + 1;
                    lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                    *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                    lVar9 = *(longlong *)(lVar9 + 0x10);
                    *(undefined4 *)((longlong)pplVar24 + 0x24) = uVar35;
                    plVar14 = *(longlong **)(lVar9 + 0x2e8);
                    plVar17 = pplVar24[-1];
                    plVar12 = (longlong *)plVar14[1];
                    *plVar12 = (longlong)(pplVar24 + -2);
                    pplVar24[-2] = plVar14;
                    pplVar24[-1] = (longlong *)((ulonglong)((uint)plVar17 & 3) | (ulonglong)plVar12)
                    ;
                    plVar14[1] = (longlong)(pplVar24 + -2);
                    if ((local_e8[0] != (longlong **)0x0) &&
                       (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                       *local_e8[0] == (longlong *)0x0)) {
                      (*(code *)local_e8[0][1][6])(local_e8[0]);
                    }
                  }
                  else {
                    if (DAT_23ed6a4f8 == (code *)0x0) {
                      pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      pcVar15 = *(code **)DAT_23ed6a4f8;
                      *(undefined8 *)DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = pcVar15;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    pcVar15 = _PyRuntime_exref;
                    pplVar24[3] = plVar3;
                    *plVar3 = *plVar3 + 1;
                    lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                    *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                    *(undefined4 *)((longlong)pplVar24 + 0x24) = uVar35;
                    plVar14 = *(longlong **)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
                    plVar17 = pplVar24[-1];
                    plVar12 = (longlong *)plVar14[1];
                    *plVar12 = (longlong)(pplVar24 + -2);
                    pplVar24[-2] = plVar14;
                    pplVar24[-1] = (longlong *)((ulonglong)((uint)plVar17 & 3) | (ulonglong)plVar12)
                    ;
                    plVar14[1] = (longlong)(pplVar24 + -2);
                    pplVar24[2] = (longlong *)pplVar25;
                    *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                    if ((local_e8[0] != (longlong **)0x0) &&
                       (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                       *local_e8[0] == (longlong *)0x0)) {
                      (*(code *)local_e8[0][1][6])(local_e8[0]);
                    }
                  }
                  pplVar25 = (longlong **)_Py_NoneStruct_exref;
                  local_e8[0] = pplVar24;
                  if (((code *)local_f8._0_8_ != _Py_NoneStruct_exref) &&
                     ((code *)local_f8._0_8_ != (code *)0x0)) {
                    FUN_23e91b1b0(param_1,local_f8,local_f8 + 8,local_e8);
                  }
                  plVar14 = *(longlong **)(local_f8._8_8_ + 0x28);
                  if (local_e8[0] == pplVar25) {
                    pplVar24 = (longlong **)0x0;
                  }
                  else {
                    pplVar24 = local_e8[0];
                    if (local_e8[0] != (longlong **)0x0) {
                      *local_e8[0] = (longlong *)((longlong)*local_e8[0] + 1);
                    }
                  }
                  *(longlong ***)(local_f8._8_8_ + 0x28) = pplVar24;
                  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                    (**(code **)(plVar14[1] + 0x30))();
                  }
                  plVar14 = *(longlong **)(param_1 + 0x138);
                  *(undefined8 *)(param_1 + 0x138) = local_f8._8_8_;
                  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                    (**(code **)(plVar14[1] + 0x30))();
                  }
                  *(longlong *)local_f8._0_8_ = *(longlong *)local_f8._0_8_ + -1;
                  if (*(longlong *)local_f8._0_8_ == 0) {
                    (**(code **)(*(longlong *)(local_f8._0_8_ + 8) + 0x30))();
                  }
                  if ((local_e8[0] != (longlong **)0x0) &&
                     (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                     *local_e8[0] == (longlong *)0x0)) {
                    (*(code *)local_e8[0][1][6])();
                  }
                  local_e8[0] = (longlong **)0x0;
                  local_f8 = (undefined1  [16])0x0;
                  iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                        *(undefined8 *)PyExc_Exception_exref);
                  if (iVar7 == 0) {
                    pplVar24 = *(longlong ***)(param_1 + 0x138);
                    pplStack_b0 = pplVar24;
                    if ((pplVar24 == pplVar25) || (pplVar24 == (longlong **)0x0)) {
                      iVar7 = 0x69;
                      pplVar27 = *(longlong ***)PyExc_RuntimeError_exref;
                      pplVar26 = (longlong **)PyUnicode_FromString("No active exception to reraise")
                      ;
                      *pplVar27 = (longlong *)((longlong)*pplVar27 + 1);
LAB_23e84fe36:
                      pplVar24 = *(longlong ***)(param_1 + 0x138);
                      pplVar31 = (longlong **)0x0;
                      *(longlong **)(param_1 + 0x138) = plVar13;
                      if (pplVar24 != (longlong **)0x0) goto LAB_23e84f82f;
                      pplVar31 = (longlong **)0x0;
                    }
                    else {
                      pplVar27 = (longlong **)pplVar24[1];
                      pplVar31 = (longlong **)pplVar24[5];
                      *pplVar24 = (longlong *)((longlong)*pplVar24 + 1);
                      *pplVar27 = (longlong *)((longlong)*pplVar27 + 1);
                      iVar7 = 0;
                      pplVar26 = pplVar24;
                      if (pplVar31 == (longlong **)0x0) goto LAB_23e84fe36;
                      *pplVar31 = (longlong *)((longlong)*pplVar31 + 1);
                      if (pplVar31[3] == plVar3) {
                        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)((longlong)pplVar31 + 0x24);
                      }
                      *(longlong **)(param_1 + 0x138) = plVar13;
LAB_23e84f82f:
                      local_a8[0] = (longlong **)0x0;
                      _local_b8 = (undefined1  [16])0x0;
                      *pplVar24 = (longlong *)((longlong)*pplVar24 + -1);
                      if (*pplVar24 == (longlong *)0x0) {
                        (*(code *)pplVar24[1][6])();
                      }
                    }
                    local_240 = (longlong *)0x0;
                    local_258 = (longlong *)0x0;
                    local_230 = (longlong *)0x0;
                    local_238 = (longlong *)0x0;
                    local_250 = (longlong *)0x0;
                    local_270 = (longlong *)0x0;
                    local_a8[0] = pplVar31;
                    local_b8 = (undefined1  [8])pplVar27;
                    pplStack_b0 = pplVar26;
                    goto LAB_23e84c550;
                  }
                  plVar14 = *(longlong **)(param_1 + 0x138);
                  lVar9 = *plVar14;
                  if (lVar9 == 0) {
                    (**(code **)(plVar14[1] + 0x30))();
                    plVar14 = *(longlong **)(param_1 + 0x138);
                    *(longlong **)(param_1 + 0x138) = plVar13;
                    if (plVar14 == (longlong *)0x0) goto LAB_23e84b6d3;
                    lVar9 = *plVar14;
                  }
                  else {
                    *(longlong **)(param_1 + 0x138) = plVar13;
                  }
                  *plVar14 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    (**(code **)(plVar14[1] + 0x30))();
                  }
                }
                else {
                  *(undefined4 *)(plVar3 + 5) = 0x6b;
                  local_280 = (longlong *)FUN_23e91bfe0(param_1,lVar9,DAT_23eedbc48);
                  if (local_280 == (longlong *)0x0) {
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e854283;
                  }
                  iVar7 = FUN_23a35f020(local_280);
                  if (iVar7 == -1) {
LAB_23e84f4e6:
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    uVar35 = 0x6c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_248 = (longlong *)0x0;
                    local_268 = (code *)0x0;
                    local_278 = (longlong *)0x0;
                    local_260 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84f535;
                  }
                  if (iVar7 != 0) {
                    iVar7 = FUN_23e983ac0(local_280,plVar1);
                    if (iVar7 == -1) goto LAB_23e84f4e6;
                    if (iVar7 != 1) goto LAB_23e84b6b1;
                    lVar9 = FUN_23e8daff0();
                    if (lVar9 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbbb0);
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x6d;
                      plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23eedbbb8);
                      if (plVar13 != (longlong *)0x0) {
                        plVar14 = (longlong *)FUN_23a388310(plVar13);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        if (plVar14 != (longlong *)0x0) {
                          local_260 = (longlong *)FUN_23a3c1d30(param_1,local_b8,plVar14,0,2);
                          if (local_260 == (longlong *)0x0) {
                            plVar13 = (longlong *)0x0;
                            *plVar14 = *plVar14 + -1;
                            pplVar25 = local_a8[0];
                            auVar32 = local_b8;
                            pplVar24 = pplStack_b0;
                            if (*plVar14 != 0) goto LAB_23e852416;
LAB_23e8525e9:
                            pplStack_b0 = (longlong **)0x0;
                            local_b8 = (undefined1  [8])0x0;
                            local_a8[0] = (longlong **)0x0;
                            FUN_23a334bc0(plVar14);
                            local_a8[0] = (longlong **)0x0;
                            local_b8 = (undefined1  [8])0x0;
                            pplStack_b0 = (longlong **)0x0;
                            if (local_260 != (longlong *)0x0) {
LAB_23e85256e:
                              pplStack_b0 = (longlong **)0x0;
                              local_b8 = (undefined1  [8])0x0;
                              local_a8[0] = (longlong **)0x0;
                              lVar9 = *local_260;
                              *local_260 = lVar9 + -1;
                              if (lVar9 + -1 == 0) {
                                FUN_23a334bc0(local_260);
                              }
                            }
                            if ((plVar13 != (longlong *)0x0) &&
                               (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                              FUN_23a334bc0(plVar13);
                            }
                            goto LAB_23e852416;
                          }
                          plVar13 = (longlong *)FUN_23a3c1d30(param_1,local_b8,plVar14,1,2);
                          if ((plVar13 == (longlong *)0x0) ||
                             (cVar6 = FUN_23a3884a0(param_1,local_b8), cVar6 == '\0')) {
                            *plVar14 = *plVar14 + -1;
                            pplVar25 = local_a8[0];
                            auVar32 = local_b8;
                            pplVar24 = pplStack_b0;
                            if (*plVar14 == 0) goto LAB_23e8525e9;
                            goto LAB_23e85256e;
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          if (*local_260 == 0) {
                            FUN_23a334bc0(local_260);
                          }
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          lVar9 = FUN_23e8daff0();
                          if (lVar9 == 0) {
                            FUN_23e915740(param_1,local_b8);
                            pplVar25 = local_a8[0];
                            auVar32 = local_b8;
                            pplVar24 = pplStack_b0;
                          }
                          else {
                            plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbb8);
                            if (plVar14 != (longlong *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 0x70;
                              plVar17 = (longlong *)FUN_23e914090(param_1,plVar14);
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                FUN_23a334bc0(plVar14);
                              }
                              if (plVar17 != (longlong *)0x0) {
                                plVar14 = (longlong *)FUN_23a388310(plVar17);
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  FUN_23a334bc0(plVar17);
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  local_268 = (code *)FUN_23a3c1d30(param_1,local_b8,plVar14,0,2);
                                  if (local_268 == (code *)0x0) {
                                    *plVar14 = *plVar14 + -1;
                                    local_278 = (longlong *)0x0;
                                    pplVar25 = local_a8[0];
                                    auVar32 = local_b8;
                                    pplVar24 = pplStack_b0;
                                    if (*plVar14 != 0) goto LAB_23e8524f4;
LAB_23e85284b:
                                    pplStack_b0 = (longlong **)0x0;
                                    local_b8 = (undefined1  [8])0x0;
                                    local_a8[0] = (longlong **)0x0;
                                    FUN_23a334bc0(plVar14);
                                    local_a8[0] = (longlong **)0x0;
                                    local_b8 = (undefined1  [8])0x0;
                                    pplStack_b0 = (longlong **)0x0;
                                    if (local_268 != (code *)0x0) {
LAB_23e8527ad:
                                      pplStack_b0 = (longlong **)0x0;
                                      local_b8 = (undefined1  [8])0x0;
                                      local_a8[0] = (longlong **)0x0;
                                      lVar9 = *(longlong *)local_268;
                                      *(longlong *)local_268 = lVar9 + -1;
                                      if (lVar9 + -1 == 0) {
                                        FUN_23a334bc0(local_268);
                                      }
                                    }
                                    if ((local_278 != (longlong *)0x0) &&
                                       (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0
                                       )) {
                                      FUN_23a334bc0(local_278);
                                    }
                                    goto LAB_23e8524f4;
                                  }
                                  local_278 = (longlong *)FUN_23a3c1d30(param_1);
                                  if ((local_278 == (longlong *)0x0) ||
                                     (cVar6 = FUN_23a3884a0(param_1), cVar6 == '\0')) {
                                    *plVar14 = *plVar14 + -1;
                                    pplVar25 = local_a8[0];
                                    auVar32 = local_b8;
                                    pplVar24 = pplStack_b0;
                                    if (*plVar14 == 0) goto LAB_23e85284b;
                                    goto LAB_23e8527ad;
                                  }
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  if (*(longlong *)local_268 == 0) {
                                    FUN_23a334bc0(local_268);
                                  }
                                  *local_278 = *local_278 + 1;
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  lVar9 = *local_278;
                                  *local_278 = lVar9 + -1;
                                  if (lVar9 + -1 == 0) {
                                    FUN_23a334bc0(local_278);
                                  }
                                  iVar7 = FUN_23e983ac0();
                                  if (iVar7 == -1) {
                                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                    uVar35 = 0x72;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_248 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                    goto LAB_23e84f535;
                                  }
                                  local_248 = (longlong *)0x0;
                                  if (iVar7 != 1) goto LAB_23e84b6d3;
                                  uVar22 = FUN_23e9373d0();
                                  plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                                  if (plVar13 != (longlong *)0x0) {
                                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    if (plVar14 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar3 + 5) = 0x75;
                                      local_88 = _Py_TrueStruct_exref;
                                      local_98 = local_260;
                                      pcStack_90 = local_268;
                                      local_248 = (longlong *)
                                                  FUN_23e9578c0(param_1,plVar14,DAT_23eedbc60);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      if (local_248 != (longlong *)0x0) {
                                        iVar7 = FUN_23a35f020(local_248);
                                        if (iVar7 == -1) {
                                          local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                          uVar35 = 0x79;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                          goto LAB_23e84f535;
                                        }
                                        if (iVar7 == 0) goto LAB_23e84b6d3;
                                        lVar9 = FUN_23e8daec0();
                                        if (lVar9 == 0) {
LAB_23e8526ab:
                                          FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e852662:
                                          local_c8 = local_a8[0];
                                          local_a8[0] = (longlong **)0x0;
                                          local_d8 = (longlong **)local_b8;
                                          pplStack_d0 = pplStack_b0;
                                          local_b8 = (undefined1  [8])0x0;
                                          pplStack_b0 = (longlong **)0x0;
                                          FUN_23a35d6b0(&local_d8);
                                        }
                                        else {
                                          plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc68);
                                          if (plVar13 == (longlong *)0x0) {
LAB_23e852639:
                                            local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e852662;
                                          }
                                          *(undefined4 *)(plVar3 + 5) = 0x7c;
                                          plVar14 = (longlong *)
                                                    FUN_23e914090(param_1,plVar13,plVar1);
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0(plVar13);
                                          }
                                          if (plVar14 == (longlong *)0x0) goto LAB_23e852639;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                          lVar9 = FUN_23e8daec0();
                                          if (lVar9 == 0) goto LAB_23e8526ab;
                                          plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc70);
                                          if (plVar13 == (longlong *)0x0) goto LAB_23e852639;
                                          *(undefined4 *)(plVar3 + 5) = 0x7d;
                                          plVar14 = (longlong *)
                                                    FUN_23e914090(param_1,plVar13,plVar1);
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0(plVar13);
                                          }
                                          if (plVar14 == (longlong *)0x0) goto LAB_23e852639;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                          }
                                        }
                                        uVar22 = FUN_23e9373d0();
                                        plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                                        if (plVar13 != (longlong *)0x0) {
                                          plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58)
                                          ;
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0(plVar13);
                                          }
                                          if (plVar14 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar3 + 5) = 0x82;
                                            local_88 = _Py_FalseStruct_exref;
                                            local_98 = local_260;
                                            pcStack_90 = local_268;
                                            plVar13 = (longlong *)
                                                      FUN_23e9578c0(param_1,plVar14,DAT_23eedbc60);
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            if (plVar13 != (longlong *)0x0) {
                                              *plVar13 = *plVar13 + -1;
                                              if (*plVar13 == 0) {
                                                FUN_23a334bc0(plVar13);
                                              }
                                              goto LAB_23e84b6d3;
                                            }
                                          }
                                        }
                                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                        uVar35 = 0x82;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                        goto LAB_23e84f535;
                                      }
                                    }
                                  }
                                  local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                  uVar35 = 0x75;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_248 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                  goto LAB_23e84f535;
                                }
                              }
                            }
                            auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplVar25 = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplVar24 = *(longlong ***)(param_1 + 0x68);
                          }
LAB_23e8524f4:
                          uVar35 = 0x70;
                          local_248 = (longlong *)0x0;
                          local_268 = (code *)0x0;
                          local_278 = plVar13;
                          local_a8[0] = pplVar25;
                          local_b8 = auVar32;
                          pplStack_b0 = pplVar24;
                          goto LAB_23e84f535;
                        }
                      }
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                    }
LAB_23e852416:
                    uVar35 = 0x6d;
                    local_248 = (longlong *)0x0;
                    local_268 = (code *)0x0;
                    local_278 = (longlong *)0x0;
                    local_260 = (longlong *)0x0;
                    local_a8[0] = pplVar25;
                    local_b8 = auVar32;
                    pplStack_b0 = pplVar24;
                    goto LAB_23e84f535;
                  }
LAB_23e84b6b1:
                  local_248 = (longlong *)0x0;
                  local_268 = (code *)0x0;
                  local_278 = (longlong *)0x0;
                  local_260 = (longlong *)0x0;
                }
LAB_23e84b6d3:
                lVar16 = FUN_23e8dac20();
                lVar9 = DAT_23eedbc38;
                uVar22 = DAT_23eedbc20;
                if (lVar16 == 0) {
                  FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
LAB_23e85247c:
                  local_270 = (longlong *)0x0;
                  iVar7 = 0x89;
                  local_240 = (longlong *)0x0;
                  local_258 = (longlong *)0x0;
                  local_230 = (longlong *)0x0;
                  local_238 = (longlong *)0x0;
                  local_250 = (longlong *)0x0;
                  pplVar25 = (longlong **)_Py_NoneStruct_exref;
                }
                else {
                  *(undefined4 *)(plVar3 + 5) = 0x89;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                  if (plVar13 == (longlong *)0x0) {
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e85247c;
                  }
                  lVar9 = *plVar13;
                  *plVar13 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if ((DAT_23ed8fb50 == 0) &&
                     (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                    DAT_23ed8fb50 = 0;
                    goto LAB_23e84ddfa;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc78);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84fc3d:
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e84fc66:
                    local_258 = (longlong *)0x0;
                    local_230 = (longlong *)0x0;
                    local_238 = (longlong *)0x0;
                    local_250 = (longlong *)0x0;
                    local_270 = (longlong *)0x0;
LAB_23e84bf8d:
                    local_128 = local_a8[0];
                    local_a8[0] = (longlong **)0x0;
                    local_138 = (longlong **)local_b8;
                    pplStack_130 = pplStack_b0;
                    local_b8 = (undefined1  [8])0x0;
                    pplStack_b0 = (longlong **)0x0;
                    FUN_23a35d6b0(&local_138);
                  }
                  else {
                    if ((DAT_23ed8fb50 == 0) &&
                       (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                      DAT_23ed8fb50 = 0;
                      goto LAB_23e84ddfa;
                    }
                    plVar14 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc80);
                    if (plVar14 == (longlong *)0x0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      goto LAB_23e84fc66;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x93;
                    local_270 = (longlong *)FUN_23e914090(param_1,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (local_270 == (longlong *)0x0) goto LAB_23e84fc3d;
                    if ((DAT_23ed8fb50 == 0) &&
                       (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                      DAT_23ed8fb50 = 0;
                      goto LAB_23e84ddfa;
                    }
                    lVar9 = FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc88);
                    if (lVar9 == 0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e84bf5a:
                      local_258 = (longlong *)0x0;
                      local_230 = (longlong *)0x0;
                      local_238 = (longlong *)0x0;
                      local_250 = (longlong *)0x0;
                      local_a8[0] = pplVar25;
                      local_b8 = auVar32;
                      pplStack_b0 = pplVar24;
                      goto LAB_23e84bf8d;
                    }
                    lVar16 = *(longlong *)(param_1 + 0x10);
                    plVar13 = *(longlong **)(lVar16 + 0xe18);
                    if (plVar13 == (longlong *)0x0) {
                      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
                      lVar34 = *plVar13 + 1;
                    }
                    else {
                      lVar4 = plVar13[3];
                      *(int *)(lVar16 + 0xeb8) = *(int *)(lVar16 + 0xeb8) + -1;
                      lVar34 = 2;
                      *(longlong *)(lVar16 + 0xe18) = lVar4;
                      *plVar13 = 1;
                    }
                    lVar16 = *(longlong *)
                              (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8
                              );
                    lVar4 = plVar13[-1];
                    puVar5 = *(undefined8 **)(lVar16 + 8);
                    *puVar5 = plVar13 + -2;
                    plVar13[-2] = lVar16;
                    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
                    *(longlong **)(lVar16 + 8) = plVar13 + -2;
                    plVar13[3] = lVar9;
                    *plVar13 = lVar34;
                    plVar14 = (longlong *)FUN_23ebf7b50(param_1,plVar13);
                    lVar9 = DAT_23ed6cce8;
                    if (plVar14 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar17 = (longlong *)0x0;
                      local_258 = (longlong *)0x0;
                      local_240 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e84bea2;
                    }
                    lVar16 = *(longlong *)(param_1 + 0x10);
                    iVar7 = *(int *)(lVar16 + 0x1410);
                    plVar17 = *(longlong **)(DAT_23ed6cce8 + 0x20);
                    *plVar17 = *plVar17 + 1;
                    if (iVar7 == 0) {
                      local_240 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
                      plVar17 = *(longlong **)(lVar9 + 0x20);
                    }
                    else {
                      iVar7 = iVar7 + -1;
                      *(int *)(lVar16 + 0x1410) = iVar7;
                      local_240 = *(longlong **)(lVar16 + 0x1190 + (longlong)iVar7 * 8);
                      *local_240 = 1;
                    }
                    lVar9 = *(longlong *)(lVar9 + 0x28);
                    local_240[2] = 0;
                    local_240[3] = 1;
                    local_240[4] = (longlong)plVar17;
                    local_240[5] = lVar9;
                    iVar7 = FUN_23a35f020(plVar14);
                    pcVar15 = PyType_Type_exref;
                    if (iVar7 == -1) {
LAB_23e850a15:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar17 = (longlong *)0x0;
                      local_258 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e84bea2:
                      pplStack_b0 = pplVar24;
                      local_b8 = auVar32;
                      local_a8[0] = pplVar25;
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if ((local_240 != (longlong *)0x0) &&
                         (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
                        (**(code **)(local_240[1] + 0x30))(local_240);
                      }
                      if ((local_258 != (longlong *)0x0) &&
                         (lVar9 = *local_258, *local_258 = lVar9 + -1, lVar9 + -1 == 0)) {
                        (**(code **)(local_258[1] + 0x30))(local_258);
                      }
                      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0))
                      {
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                      }
                      goto LAB_23e84bf5a;
                    }
                    if (iVar7 != 0) {
                      plVar17 = (longlong *)FUN_23a388650(param_1,plVar14);
                      if (plVar17 != (longlong *)0x0) {
                        pcVar15 = (code *)FUN_23e8ba4a0(plVar17[1]);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0(plVar17);
                        }
                        if (pcVar15 != (code *)0x0) goto LAB_23e84b94a;
                      }
                      goto LAB_23e850a15;
                    }
                    *(longlong *)PyType_Type_exref = *(longlong *)PyType_Type_exref + 1;
LAB_23e84b94a:
                    local_258 = (longlong *)FUN_23e8bc0c0(param_1,pcVar15);
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    if (local_258 == (longlong *)0x0) goto LAB_23e850a15;
                    iVar7 = FUN_23e8be270(param_1,local_258);
                    if (iVar7 == -1) goto LAB_23e85099f;
                    if (iVar7 != 0) {
                      plVar12 = (longlong *)FUN_23e8bc2f0(local_258,DAT_23eedbc90);
                      plVar17 = DAT_23eedbc98;
                      if (plVar12 != (longlong *)0x0) {
                        plVar20 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar17 = *plVar17 + 1;
                        plVar20[3] = (longlong)plVar17;
                        *plVar14 = *plVar14 + 1;
                        plVar20[4] = (longlong)plVar14;
                        *(undefined4 *)(plVar3 + 5) = 0x95;
                        plVar17 = (longlong *)FUN_23a334c60(param_1,plVar12);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        if (plVar17 != (longlong *)0x0) {
                          iVar7 = FUN_23e8be270(param_1,plVar17);
                          if (iVar7 == -1) {
LAB_23e85093c:
                            auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplVar25 = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplVar24 = *(longlong ***)(param_1 + 0x68);
                          }
                          else {
                            pcVar15 = _Py_FalseStruct_exref;
                            if (iVar7 != 0) {
                              pcVar15 = _Py_TrueStruct_exref;
                            }
                            iVar7 = FUN_23a35f020(pcVar15);
                            uVar22 = DAT_23eedbca8;
                            if (iVar7 != 0) goto LAB_23e84ba6c;
                            lVar9 = FUN_23e8bbbe0(param_1,local_258);
                            if (lVar9 == 0) goto LAB_23e85093c;
                            plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                            lVar16 = plVar17[1];
                            plVar12[3] = lVar9;
                            plVar20 = (longlong *)FUN_23e8ba4a0(lVar16);
                            lVar9 = FUN_23e8bc2f0(plVar20,DAT_23ed6cd48);
                            *plVar20 = *plVar20 + -1;
                            if (*plVar20 == 0) {
                              FUN_23a334bc0();
                            }
                            if (lVar9 == 0) {
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar12 = *plVar12 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                                pplVar25 = local_a8[0];
                                auVar32 = local_b8;
                                pplVar24 = pplStack_b0;
                              }
                            }
                            else {
                              plVar12[4] = lVar9;
                              plVar20 = (longlong *)FUN_23e8c2a30(uVar22,plVar12);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0();
                              }
                              pcVar15 = PyExc_TypeError_exref;
                              if (plVar20 == (longlong *)0x0) goto LAB_23e85093c;
                              *(undefined4 *)(plVar3 + 5) = 0x95;
                              pplVar25 = (longlong **)FUN_23e914090(param_1,*(undefined8 *)pcVar15);
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                FUN_23a334bc0(plVar20);
                              }
                              local_b8 = (undefined1  [8])pplVar25;
                              FUN_23e91b7d0(param_1,local_b8);
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                            }
                          }
                          goto LAB_23e84bea2;
                        }
                      }
LAB_23e85099f:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e84bea2;
                    }
                    plVar17 = (longlong *)FUN_23e8d6ad0(param_1);
LAB_23e84ba6c:
                    *plVar17 = *plVar17 + 1;
                    iVar7 = PyObject_SetItem(plVar17,DAT_23ed6cd38);
                    if ((iVar7 != 0) ||
                       (iVar7 = PyObject_SetItem(plVar17,DAT_23eedbcc8), plVar12 = DAT_23eede360,
                       iVar7 != 0)) goto LAB_23e852062;
                    if (DAT_23eede360 == (longlong *)0x0) {
LAB_23e84bae9:
                      DAT_23eede360 =
                           (longlong *)FUN_23e93db80(param_1,DAT_23eede358,DAT_23eede398,0x10);
                    }
                    else {
                      lVar9 = *DAT_23eede360;
                      if (1 < lVar9) {
                        *DAT_23eede360 = lVar9 + -1;
                        goto LAB_23e84bae9;
                      }
                      if (DAT_23eede360[2] != 0) {
                        *DAT_23eede360 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        goto LAB_23e84bae9;
                      }
                    }
                    plVar20 = DAT_23eede360;
                    FUN_23ebf7130(*(undefined8 *)(param_1 + 0x38));
                    *plVar20 = *plVar20 + 1;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(undefined4 *)(plVar20 + 8) = 0;
                    plVar12 = DAT_23eedbcd0;
                    plVar18 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar12 = *plVar12 + 1;
                    plVar18[3] = (longlong)plVar12;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbcd8);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                      }
                      uVar35 = 0x97;
                      local_250 = (longlong *)&DAT_23ec5e407;
LAB_23e84bdcc:
                      pplVar25 = local_a8[0];
                      if (local_a8[0] == (longlong **)0x0) {
                        pplVar24 = (longlong **)FUN_23e8d6280(plVar20,uVar35);
                        if ((local_a8[0] != (longlong **)0x0) &&
                           (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                           *local_a8[0] == (longlong *)0x0)) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        pplVar24 = local_a8[0];
                        if (local_a8[0][3] != plVar20) {
                          pplVar24 = (longlong **)FUN_23e8d6280(plVar20,uVar35);
                          pplVar24[2] = (longlong *)pplVar25;
                          *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                          if ((local_a8[0] != (longlong **)0x0) &&
                             (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                             *local_a8[0] == (longlong *)0x0)) {
                            FUN_23a334bc0();
                          }
                        }
                      }
                      local_a8[0] = pplVar24;
                      FUN_23e8bba40(plVar20,local_250);
                      if (DAT_23eede360 == plVar20) {
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        DAT_23eede360 = (longlong *)0x0;
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
LAB_23e84be5c:
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      _local_b8 = (undefined1  [16])0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        FUN_23a334bc0(plVar17);
                      }
                      goto LAB_23e84bea2;
                    }
                    plVar18[4] = lVar9;
                    plVar19 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),5);
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)plVar19[3] = plVar18;
                    plVar12 = DAT_23eedbce0;
                    plVar18 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar12 = *plVar12 + 1;
                    plVar18[3] = (longlong)plVar12;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbcd8);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                      }
                      uVar35 = 0x98;
                      local_250 = (longlong *)&DAT_23ec5e407;
LAB_23e8520e2:
                      *plVar19 = *plVar19 + -1;
                      if (*plVar19 == 0) {
                        FUN_23a334bc0(plVar19);
                      }
                      goto LAB_23e84bdcc;
                    }
                    plVar18[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar19[3] + 8) = plVar18;
                    plVar12 = DAT_23eedbce8;
                    plVar18 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar12 = *plVar12 + 1;
                    plVar18[3] = (longlong)plVar12;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                      }
                      uVar35 = 0x99;
                      local_250 = (longlong *)&DAT_23ec5e407;
                      goto LAB_23e8520e2;
                    }
                    plVar18[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar19[3] + 0x10) = plVar18;
                    plVar12 = DAT_23eedbc18;
                    plVar18 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar12 = *plVar12 + 1;
                    plVar18[3] = (longlong)plVar12;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                      }
                      uVar35 = 0x9a;
                      local_250 = (longlong *)&DAT_23ec5e407;
                      goto LAB_23e8520e2;
                    }
                    plVar18[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar19[3] + 0x18) = plVar18;
                    plVar12 = DAT_23eedbcf0;
                    lVar9 = FUN_23e916ad0(uVar22,2);
                    uVar22 = DAT_23eedbcf8;
                    *plVar12 = *plVar12 + 1;
                    *(longlong **)(lVar9 + 0x18) = plVar12;
                    local_250 = (longlong *)PyObject_GetItem(plVar17,uVar22);
                    if (local_250 == (longlong *)0x0) {
                      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_KeyError_exref);
                      if (cVar6 == '\0') {
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_250 = (longlong *)0x0;
                        uVar35 = 0;
                        goto LAB_23e8520e2;
                      }
                      *local_270 = *local_270 + 1;
                      local_250 = local_270;
                    }
                    *(longlong **)(lVar9 + 0x20) = local_250;
                    *(longlong *)(plVar19[3] + 0x20) = lVar9;
                    iVar7 = PyObject_SetItem(plVar17,DAT_23eedbd00);
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    if (iVar7 != 0) {
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      uVar35 = 0x96;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_250 = (longlong *)&DAT_23ec5e407;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84bdcc;
                    }
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    iVar7 = FUN_23e9875b0(plVar14,plVar13);
                    if ((iVar7 == -1) ||
                       ((iVar7 == 1 && (iVar7 = PyObject_SetItem(plVar17,DAT_23eedbd08), iVar7 != 0)
                        ))) {
LAB_23e852062:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84be5c;
                    }
                    plVar12 = DAT_23eedbc98;
                    plVar20 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                    *plVar12 = *plVar12 + 1;
                    plVar20[3] = (longlong)plVar12;
                    *plVar14 = *plVar14 + 1;
                    plVar20[4] = (longlong)plVar14;
                    *plVar17 = *plVar17 + 1;
                    plVar20[5] = (longlong)plVar17;
                    *(undefined4 *)(plVar3 + 5) = 0x95;
                    local_250 = (longlong *)FUN_23a334c60(param_1,local_258);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    if (local_250 == (longlong *)0x0) goto LAB_23e852062;
                    *local_250 = *local_250 + 1;
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                    lVar9 = *local_250;
                    *local_250 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_250);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar9 = *local_240;
                    *local_240 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_240);
                    }
                    lVar9 = *local_258;
                    *local_258 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_258);
                    }
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                    pcVar15 = _Py_NoneStruct_exref;
                    if (*(longlong *)_Py_NoneStruct_exref == 0) {
                      FUN_23a334bc0(_Py_NoneStruct_exref);
                    }
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc88);
                    if (lVar9 == 0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e85134c:
                      local_258 = (longlong *)0x0;
                      local_230 = (longlong *)0x0;
                      local_238 = (longlong *)0x0;
                      local_a8[0] = pplVar25;
                      local_b8 = auVar32;
                      pplStack_b0 = pplVar24;
                      goto LAB_23e84bf8d;
                    }
                    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),1);
                    *plVar13 = *plVar13 + 1;
                    plVar13[3] = lVar9;
                    plVar14 = (longlong *)FUN_23ebf7b50(param_1);
                    if (plVar14 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      local_258 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_240 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e851284;
                    }
                    local_240 = (longlong *)FUN_23e8d6ad0(param_1);
                    iVar7 = FUN_23a35f020(plVar14);
                    pcVar30 = PyType_Type_exref;
                    if (iVar7 == -1) {
LAB_23e851fa9:
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plVar17 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_258 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e851284:
                      pplStack_b0 = pplVar24;
                      local_b8 = auVar32;
                      local_a8[0] = pplVar25;
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      local_a8[0] = (longlong **)0x0;
                      lVar9 = *plVar13;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      *plVar13 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0))
                      {
                        FUN_23a334bc0(plVar14);
                      }
                      if ((local_240 != (longlong *)0x0) &&
                         (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
                        FUN_23a334bc0(local_240);
                      }
                      if ((local_258 != (longlong *)0x0) &&
                         (lVar9 = *local_258, *local_258 = lVar9 + -1, lVar9 + -1 == 0)) {
                        FUN_23a334bc0(local_258);
                      }
                      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0))
                      {
                        FUN_23a334bc0(plVar17);
                      }
                      goto LAB_23e85134c;
                    }
                    if (iVar7 != 0) {
                      plVar17 = (longlong *)FUN_23a388650(param_1,plVar14,DAT_23ed6ccf0,0);
                      if (plVar17 != (longlong *)0x0) {
                        pcVar30 = (code *)FUN_23e8ba4a0(plVar17[1]);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0(plVar17);
                        }
                        if (pcVar30 != (code *)0x0) goto LAB_23e850e8f;
                      }
                      goto LAB_23e851fa9;
                    }
                    *(longlong *)PyType_Type_exref = *(longlong *)PyType_Type_exref + 1;
LAB_23e850e8f:
                    local_258 = (longlong *)FUN_23e8bc0c0(param_1,pcVar30,plVar14);
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (local_258 == (longlong *)0x0) goto LAB_23e851fa9;
                    iVar7 = FUN_23e8be270(param_1,local_258,DAT_23eedbc90);
                    if (iVar7 == -1) goto LAB_23e851f34;
                    if (iVar7 != 0) {
                      plVar12 = (longlong *)FUN_23e8bc2f0(local_258,DAT_23eedbc90);
                      plVar17 = DAT_23eedbd10;
                      if (plVar12 != (longlong *)0x0) {
                        plVar20 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar17 = *plVar17 + 1;
                        plVar20[3] = (longlong)plVar17;
                        *plVar14 = *plVar14 + 1;
                        plVar20[4] = (longlong)plVar14;
                        *(undefined4 *)(plVar3 + 5) = 0x9e;
                        plVar17 = (longlong *)FUN_23a334c60(param_1,plVar12,plVar20,local_240);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        if (plVar17 != (longlong *)0x0) {
                          iVar7 = FUN_23e8be270(param_1,plVar17,DAT_23eedbca0);
                          if (iVar7 == -1) {
LAB_23e851ed1:
                            auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplVar25 = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplVar24 = *(longlong ***)(param_1 + 0x68);
                          }
                          else {
                            pcVar30 = _Py_FalseStruct_exref;
                            if (iVar7 != 0) {
                              pcVar30 = _Py_TrueStruct_exref;
                            }
                            iVar7 = FUN_23a35f020(pcVar30);
                            uVar22 = DAT_23eedbca8;
                            if (iVar7 != 0) goto LAB_23e850fb0;
                            lVar9 = FUN_23e8bbbe0(param_1,local_258,DAT_23ed6cd48,DAT_23eedbcb0);
                            if (lVar9 == 0) goto LAB_23e851ed1;
                            plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                            lVar16 = plVar17[1];
                            plVar12[3] = lVar9;
                            plVar20 = (longlong *)FUN_23e8ba4a0(lVar16);
                            lVar9 = FUN_23e8bc2f0(plVar20,DAT_23ed6cd48);
                            *plVar20 = *plVar20 + -1;
                            if (*plVar20 == 0) {
                              FUN_23a334bc0();
                            }
                            if (lVar9 == 0) {
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar12 = *plVar12 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                                pplVar25 = local_a8[0];
                                auVar32 = local_b8;
                                pplVar24 = pplStack_b0;
                              }
                            }
                            else {
                              plVar12[4] = lVar9;
                              plVar20 = (longlong *)FUN_23e8c2a30(uVar22,plVar12);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              pcVar15 = PyExc_TypeError_exref;
                              if (plVar20 == (longlong *)0x0) goto LAB_23e851ed1;
                              *(undefined4 *)(plVar3 + 5) = 0x9e;
                              pplVar25 = (longlong **)
                                         FUN_23e914090(param_1,*(undefined8 *)pcVar15,plVar20);
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                FUN_23a334bc0(plVar20);
                              }
                              local_b8 = (undefined1  [8])pplVar25;
                              FUN_23e91b7d0(param_1,local_b8);
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                            }
                          }
                          goto LAB_23e851284;
                        }
                      }
LAB_23e851f34:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      plVar17 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e851284;
                    }
                    plVar17 = (longlong *)FUN_23e8d6ad0(param_1);
LAB_23e850fb0:
                    *plVar17 = *plVar17 + 1;
                    iVar7 = PyObject_SetItem(plVar17,DAT_23ed6cd38,DAT_23eedbcb8);
                    if ((iVar7 != 0) ||
                       (iVar7 = PyObject_SetItem(plVar17,DAT_23eedbcc8,DAT_23eedbd18),
                       plVar12 = DAT_23eede350, iVar7 != 0)) goto LAB_23e851c94;
                    if (DAT_23eede350 == (longlong *)0x0) {
LAB_23e851026:
                      DAT_23eede350 =
                           (longlong *)FUN_23e93db80(param_1,DAT_23eede348,DAT_23eede398,0x10);
                    }
                    else {
                      lVar9 = *DAT_23eede350;
                      if (1 < lVar9) {
                        *DAT_23eede350 = lVar9 + -1;
                        goto LAB_23e851026;
                      }
                      if (DAT_23eede350[2] != 0) {
                        *DAT_23eede350 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        goto LAB_23e851026;
                      }
                    }
                    plVar20 = DAT_23eede350;
                    FUN_23ebf7130(*(undefined8 *)(param_1 + 0x38),DAT_23eede350 + 9);
                    *plVar20 = *plVar20 + 1;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(undefined4 *)(plVar20 + 8) = 0;
                    plVar12 = DAT_23ed6cf78;
                    plVar18 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar12 = *plVar12 + 1;
                    plVar18[3] = (longlong)plVar12;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        FUN_23a334bc0(plVar18);
                      }
                      uVar35 = 0xa0;
                      puVar33 = &DAT_23ec5e407;
LAB_23e8511b4:
                      pplVar25 = local_a8[0];
                      if (local_a8[0] == (longlong **)0x0) {
                        pplVar24 = (longlong **)FUN_23e8d6280(plVar20,uVar35);
                        if ((local_a8[0] != (longlong **)0x0) &&
                           (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                           *local_a8[0] == (longlong *)0x0)) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        pplVar24 = local_a8[0];
                        if (local_a8[0][3] != plVar20) {
                          pplVar24 = (longlong **)FUN_23e8d6280(plVar20,uVar35);
                          pplVar24[2] = (longlong *)pplVar25;
                          *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                          if ((local_a8[0] != (longlong **)0x0) &&
                             (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                             *local_a8[0] == (longlong *)0x0)) {
                            FUN_23a334bc0();
                          }
                        }
                      }
                      local_a8[0] = pplVar24;
                      FUN_23e8bba40(plVar20,puVar33,0,local_250);
                      if (DAT_23eede350 == plVar20) {
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        DAT_23eede350 = (longlong *)0x0;
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
LAB_23e85123f:
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      _local_b8 = (undefined1  [16])0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        FUN_23a334bc0(plVar17);
                      }
                      goto LAB_23e851284;
                    }
                    plVar18[4] = lVar9;
                    plVar19 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),2);
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)plVar19[3] = plVar18;
                    plVar18 = DAT_23eedbd20;
                    lVar9 = FUN_23e916ad0(uVar22,2);
                    *plVar18 = *plVar18 + 1;
                    plVar12 = DAT_23eedbc98;
                    *(longlong **)(lVar9 + 0x18) = plVar18;
                    plVar12 = (longlong *)PyObject_GetItem(plVar17,plVar12);
                    if (plVar12 == (longlong *)0x0) {
                      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_KeyError_exref);
                      if (cVar6 == '\0') {
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        puVar33 = (undefined *)0x0;
                        uVar35 = 0;
                        goto LAB_23e8511b4;
                      }
                      *local_250 = *local_250 + 1;
                      plVar12 = local_250;
                    }
                    lVar16 = plVar19[3];
                    *(longlong **)(lVar9 + 0x20) = plVar12;
                    *(longlong *)(lVar16 + 8) = lVar9;
                    iVar7 = PyObject_SetItem(plVar17,DAT_23eedbd00);
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    if (iVar7 != 0) {
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      uVar35 = 0x9f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      puVar33 = &DAT_23ec5e407;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e8511b4;
                    }
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    iVar7 = FUN_23e9875b0();
                    if ((iVar7 == -1) ||
                       ((iVar7 == 1 &&
                        (iVar7 = PyObject_SetItem(plVar17,DAT_23eedbd08,plVar13), iVar7 != 0)))) {
LAB_23e851c94:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e85123f;
                    }
                    plVar12 = DAT_23eedbd10;
                    plVar20 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                    *plVar12 = *plVar12 + 1;
                    plVar20[3] = (longlong)plVar12;
                    *plVar14 = *plVar14 + 1;
                    plVar20[4] = (longlong)plVar14;
                    *plVar17 = *plVar17 + 1;
                    plVar20[5] = (longlong)plVar17;
                    *(undefined4 *)(plVar3 + 5) = 0x9e;
                    local_238 = (longlong *)FUN_23a334c60(param_1,local_258,plVar20,local_240);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0();
                    }
                    if (local_238 == (longlong *)0x0) goto LAB_23e851c94;
                    *local_238 = *local_238 + 1;
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                    lVar9 = *local_238;
                    *local_238 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_238);
                    }
                    lVar9 = *plVar13;
                    *plVar13 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar9 = *local_240;
                    *local_240 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_240);
                    }
                    lVar9 = *local_258;
                    *local_258 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_258);
                    }
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbc80;
                    *(undefined4 *)(plVar3 + 5) = 0xa5;
                    local_230 = (longlong *)
                                FUN_23e915840(param_1,uVar28,uVar22,
                                              *(undefined8 *)(DAT_23eedbd28 + 0x18));
                    if (local_230 == (longlong *)0x0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_258 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84bf8d;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xa6;
                    local_258 = (longlong *)FUN_23e91a870(param_1,local_238);
                    if ((local_258 == (longlong *)0x0) ||
                       (cVar6 = FUN_23e8d9ac0(local_258,DAT_23ed6cf78,DAT_23ed6ccf8),
                       plVar13 = DAT_23eedbd30, cVar6 == '\0')) {
LAB_23e851c0b:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84bf8d;
                    }
                    pcVar15 = DAT_23ed6ccf0;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xa8;
                    plVar14 = (longlong *)FUN_23e915840(param_1,uVar28,uVar22,local_230);
                    if (plVar14 == (longlong *)0x0) goto LAB_23e851c0b;
                    *(undefined4 *)(plVar3 + 5) = 0xa8;
                    local_98 = plVar13;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar15;
                    pcStack_80 = pcVar15;
                    local_78 = plVar14;
                    plVar13 = (longlong *)FUN_23e95b390(param_1,local_250,&local_98);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    cVar6 = FUN_23e8d9ac0(local_258,DAT_23eedbd20,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (cVar6 == '\0') goto LAB_23e851c0b;
                    uVar22 = FUN_23e9373d0();
                    plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbd40);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar14 = DAT_23ed6ccf8;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    pcVar15 = (code *)FUN_23e915840(param_1,uVar28,uVar22,local_258);
                    if (pcVar15 == (code *)0x0) {
LAB_23e851bcb:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      goto LAB_23e84bf8d;
                    }
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd48;
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    pcVar30 = (code *)FUN_23e915840(param_1,uVar28,uVar22,local_258);
                    if (pcVar30 == (code *)0x0) {
LAB_23e851b7d:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                      if (*(longlong *)pcVar15 == 0) {
                        FUN_23a334bc0(pcVar15);
                      }
                      goto LAB_23e84bf8d;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    local_98 = plVar14;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar30;
                    plVar14 = (longlong *)FUN_23e956150(param_1,plVar13,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e851c0b;
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbd50;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) {
LAB_23e851b5e:
                      FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                      goto LAB_23e84bf8d;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xab;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    uVar22 = DAT_23eedbd58;
                    plVar13 = (longlong *)FUN_23e8bc2f0(local_258,DAT_23eedbd20);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    cVar6 = FUN_23e8d9ac0(plVar13,DAT_23eedbce8,uVar22);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (cVar6 == '\0') goto LAB_23e851c0b;
                    uVar22 = FUN_23e9373d0();
                    plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbd40);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    plVar14 = DAT_23ed6ccf8;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    pcVar15 = (code *)FUN_23e915840(param_1,uVar28,uVar22,local_258);
                    if (pcVar15 == (code *)0x0) goto LAB_23e851bcb;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd48;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    pcVar30 = (code *)FUN_23e915840(param_1,uVar28,uVar22,local_258);
                    if (pcVar30 == (code *)0x0) goto LAB_23e851b7d;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    local_98 = plVar14;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar30;
                    plVar14 = (longlong *)FUN_23e956150(param_1,plVar13,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e851c0b;
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbc38;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) goto LAB_23e851b5e;
                    *(undefined4 *)(plVar3 + 5) = 0xb1;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) goto LAB_23e851c0b;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = FUN_23e8daec0();
                    if (lVar9 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e851af9:
                      local_108 = local_a8[0];
                      local_a8[0] = (longlong **)0x0;
                      local_118 = (longlong **)local_b8;
                      pplStack_110 = pplStack_b0;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      FUN_23a35d6b0(&local_118);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc68);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e851ad0:
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e851af9;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0xb5;
                      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      if (plVar14 == (longlong *)0x0) goto LAB_23e851ad0;
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                    }
                  }
                  lVar16 = FUN_23e8dac20();
                  lVar9 = DAT_23eedbc38;
                  uVar22 = DAT_23eedbc20;
                  if (lVar16 == 0) {
                    iVar7 = 0xbb;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    local_240 = (longlong *)0x0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0xbb;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      iVar7 = 0xbb;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplVar25 = (longlong **)_Py_NoneStruct_exref;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_240 = (longlong *)0x0;
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    }
                    else {
                      lVar9 = *plVar13;
                      *plVar13 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      lVar9 = FUN_23e8daff0();
                      if (lVar9 == 0) {
                        FUN_23e915740(param_1,local_b8);
                        pplVar25 = local_a8[0];
                        auVar32 = local_b8;
                        pplVar24 = pplStack_b0;
LAB_23e84fbd1:
                        local_240 = (longlong *)0x0;
                        local_a8[0] = pplVar25;
                        local_b8 = auVar32;
                        pplStack_b0 = pplVar24;
LAB_23e84fbf4:
                        pplStack_170 = pplStack_b0;
                        local_178 = (longlong **)local_b8;
                        local_b8 = (undefined1  [8])0x0;
                        pplStack_b0 = (longlong **)0x0;
                        local_168 = local_a8[0];
                        local_a8[0] = (longlong **)0x0;
                        FUN_23a35d6b0(&local_178);
                      }
                      else {
                        plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbb8);
                        if (plVar13 == (longlong *)0x0) {
LAB_23e84fbb7:
                          pplVar25 = *(longlong ***)(param_1 + 0x70);
                          auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pplVar24 = *(longlong ***)(param_1 + 0x68);
                          goto LAB_23e84fbd1;
                        }
                        *(undefined4 *)(plVar3 + 5) = 0xc3;
                        plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e84fbb7;
                        plVar13 = (longlong *)FUN_23a388310(plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                        }
                        if (plVar13 == (longlong *)0x0) goto LAB_23e84fbb7;
                        plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                        if ((plVar14 == (longlong *)0x0) &&
                           (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_b8),
                           plVar14 == (longlong *)0x0)) {
                          *plVar13 = *plVar13 + -1;
                          local_240 = (longlong *)0x0;
                          pplVar25 = local_a8[0];
                          auVar32 = local_b8;
                          pplVar24 = pplStack_b0;
                          if (*plVar13 != 0) goto LAB_23e84fbd1;
LAB_23e850384:
                          pplStack_b0 = (longlong **)0x0;
                          local_b8 = (undefined1  [8])0x0;
                          local_a8[0] = (longlong **)0x0;
                          FUN_23a334bc0(plVar13);
                          local_a8[0] = (longlong **)0x0;
                          local_b8 = (undefined1  [8])0x0;
                          pplStack_b0 = (longlong **)0x0;
                          if (plVar14 != (longlong *)0x0) {
LAB_23e8502df:
                            pplStack_b0 = (longlong **)0x0;
                            local_b8 = (undefined1  [8])0x0;
                            local_a8[0] = (longlong **)0x0;
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                          }
                          if ((local_240 != (longlong *)0x0) &&
                             (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
                            (**(code **)(local_240[1] + 0x30))(local_240);
                          }
                          goto LAB_23e84fbd1;
                        }
                        local_240 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                        if (((local_240 == (longlong *)0x0) &&
                            (local_240 = (longlong *)FUN_23a3c1b70(param_1,local_b8),
                            local_240 == (longlong *)0x0)) ||
                           (cVar6 = FUN_23a3884a0(param_1,local_b8), cVar6 == '\0')) {
                          *plVar13 = *plVar13 + -1;
                          pplVar25 = local_a8[0];
                          auVar32 = local_b8;
                          pplVar24 = pplStack_b0;
                          if (*plVar13 == 0) goto LAB_23e850384;
                          goto LAB_23e8502df;
                        }
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        *plVar14 = *plVar14 + 1;
                        if ((local_278 != (longlong *)0x0) &&
                           (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0)) {
                          FUN_23a334bc0(local_278);
                        }
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        if (*local_240 == 0) {
                          FUN_23a334bc0(local_240);
                        }
                        uVar22 = FUN_23e9373d0();
                        plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                        local_278 = plVar14;
                        if (plVar13 == (longlong *)0x0) {
LAB_23e850245:
                          local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                          local_a8[0] = *(longlong ***)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                          goto LAB_23e84fbf4;
                        }
                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e850245;
                        *(undefined4 *)(plVar3 + 5) = 199;
                        plVar13 = (longlong *)FUN_23e915840(param_1,plVar14,DAT_23eedbd60,local_240)
                        ;
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar13 == (longlong *)0x0) goto LAB_23e850245;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                        lVar16 = FUN_23e8dac20();
                        lVar9 = DAT_23eedbd68;
                        uVar22 = DAT_23eedbc20;
                        if (lVar16 == 0) {
                          FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                          goto LAB_23e84fbf4;
                        }
                        *(undefined4 *)(plVar3 + 5) = 0xc9;
                        plVar13 = (longlong *)
                                  FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18))
                        ;
                        if (plVar13 == (longlong *)0x0) goto LAB_23e850245;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0();
                        }
                        lVar9 = FUN_23e8daec0();
                        if (lVar9 == 0) {
                          FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e8501d1:
                          pplStack_150 = pplStack_b0;
                          local_158 = (longlong **)local_b8;
                          local_b8 = (undefined1  [8])0x0;
                          pplStack_b0 = (longlong **)0x0;
                          local_148 = local_a8[0];
                          local_a8[0] = (longlong **)0x0;
                          FUN_23a35d6b0(&local_158);
                        }
                        else {
                          plVar13 = (longlong *)FUN_23e8bc2f0(lVar9);
                          if (plVar13 == (longlong *)0x0) {
LAB_23e8501a8:
                            local_a8[0] = *(longlong ***)(param_1 + 0x70);
                            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e8501d1;
                          }
                          *(undefined4 *)(plVar3 + 5) = 0xcd;
                          plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          if (plVar14 == (longlong *)0x0) goto LAB_23e8501a8;
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                        }
                      }
                      lVar16 = FUN_23e8dac20();
                      lVar9 = DAT_23eedbc28;
                      uVar22 = DAT_23eedbc20;
                      if (lVar16 == 0) {
                        iVar7 = 0xd3;
                        FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                        pplVar25 = (longlong **)_Py_NoneStruct_exref;
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0xd3;
                        plVar13 = (longlong *)
                                  FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18))
                        ;
                        pplVar25 = (longlong **)_Py_NoneStruct_exref;
                        if (plVar13 == (longlong *)0x0) {
                          local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                          local_a8[0] = *(longlong ***)(param_1 + 0x70);
                          iVar7 = 0xd3;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        }
                        else {
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))();
                          }
                          if ((DAT_23ed8fb50 == 0) &&
                             (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
                          {
                            DAT_23ed8fb50 = 0;
LAB_23e84ddfa:
                            FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                                          "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
                            abort();
                          }
                          plVar13 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc50);
                          if (plVar13 == (longlong *)0x0) {
LAB_23e84ee84:
                            local_a8[0] = *(longlong ***)(param_1 + 0x70);
                            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e84eead:
                            pplStack_190 = pplStack_b0;
                            local_198 = (longlong **)local_b8;
                            local_b8 = (undefined1  [8])0x0;
                            pplStack_b0 = (longlong **)0x0;
                            local_188 = local_a8[0];
                            local_a8[0] = (longlong **)0x0;
                            FUN_23a35d6b0(&local_198);
                          }
                          else {
                            plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))(plVar13);
                            }
                            if (plVar14 == (longlong *)0x0) goto LAB_23e84ee84;
                            plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbd70);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if (plVar13 == (longlong *)0x0) goto LAB_23e84ee84;
                            *(undefined4 *)(plVar3 + 5) = 0xdd;
                            pcStack_90 = _Py_TrueStruct_exref;
                            local_98 = plVar1;
                            plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0(plVar13);
                            }
                            if (plVar14 == (longlong *)0x0) goto LAB_23e84ee84;
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                            }
                            lVar16 = FUN_23e8dac20();
                            lVar9 = DAT_23eedbc28;
                            uVar22 = DAT_23eedbc20;
                            if (lVar16 == 0) {
                              FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                              goto LAB_23e84eead;
                            }
                            *(undefined4 *)(plVar3 + 5) = 0xde;
                            plVar13 = (longlong *)
                                      FUN_23e915840(param_1,lVar16,uVar22,
                                                    *(undefined8 *)(lVar9 + 0x18));
                            if (plVar13 == (longlong *)0x0) goto LAB_23e84ee84;
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0(plVar13);
                            }
                          }
                          lVar9 = FUN_23e8daec0();
                          if (lVar9 == 0) {
                            FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0xe6;
                            plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar9,DAT_23eedbc48);
                            if (plVar13 != (longlong *)0x0) {
                              if ((local_280 != (longlong *)0x0) &&
                                 (lVar9 = *local_280, *local_280 = lVar9 + -1, lVar9 + -1 == 0)) {
                                (**(code **)(local_280[1] + 0x30))(local_280);
                              }
                              iVar7 = FUN_23e912620(plVar13,plVar1);
                              local_280 = plVar13;
                              if (iVar7 == -1) {
                                local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pplVar25 = (longlong **)_Py_NoneStruct_exref;
                                iVar7 = 0xe7;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              }
                              else if (iVar7 == 1) {
                                uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
                                plVar14 = DAT_23eedbd78;
                                plVar17 = (longlong *)
                                          FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                *plVar14 = *plVar14 + 1;
                                plVar17[3] = (longlong)plVar14;
                                plVar14 = (longlong *)FUN_23e8bf9b0(plVar10,DAT_23ed6ccf8);
                                if (plVar14 == (longlong *)0x0) {
LAB_23e85003b:
                                  local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                  local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar17 = *plVar17 + -1;
                                  if (*plVar17 == 0) {
                                    FUN_23a334bc0();
                                  }
                                }
                                else {
                                  lVar9 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  plVar14 = DAT_23eedbd80;
                                  if (lVar9 == 0) goto LAB_23e85003b;
                                  plVar17[4] = lVar9;
                                  *plVar14 = *plVar14 + 1;
                                  plVar17[5] = (longlong)plVar14;
                                  plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
                                  *plVar17 = *plVar17 + -1;
                                  if (*plVar17 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plVar14 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar3 + 5) = 0xe8;
                                    plVar17 = (longlong *)FUN_23e914090(param_1,uVar22,plVar14);
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plVar17 != (longlong *)0x0) {
LAB_23e8503b1:
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                      pcVar15 = _Py_TrueStruct_exref;
                                      *(longlong *)_Py_TrueStruct_exref =
                                           *(longlong *)_Py_TrueStruct_exref + 1;
                                      *plVar10 = *plVar10 + -1;
                                      if (*plVar10 == 0) {
                                        FUN_23a334bc0(plVar10);
                                      }
                                      lVar9 = *plVar11;
                                      *plVar11 = lVar9 + -1;
                                      local_280 = plVar13;
                                      if (lVar9 + -1 == 0) {
                                        FUN_23a334bc0(plVar11);
                                      }
                                      goto LAB_23e848513;
                                    }
                                  }
                                  local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                  local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                iVar7 = 0xe8;
                                pplVar25 = (longlong **)_Py_NoneStruct_exref;
                              }
                              else {
                                FUN_23e8ba2b0(local_b8,DAT_23eedbd88);
                                pplVar25 = (longlong **)_Py_NoneStruct_exref;
                                if ((local_b8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                                   (local_b8 != (undefined1  [8])0x0)) {
                                  FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
                                }
                                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pplStack_b0);
                                iVar7 = 0xec;
                              }
                              goto LAB_23e84c550;
                            }
                            local_a8[0] = *(longlong ***)(param_1 + 0x70);
                            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          iVar7 = 0xe6;
                          pplVar25 = (longlong **)_Py_NoneStruct_exref;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_23e84c550:
        pplVar24 = local_a8[0];
        local_1b8._8_8_ = pplStack_b0;
        local_1b8._0_8_ = local_b8;
        local_a8[0] = (longlong **)0x0;
        local_b8 = (undefined1  [8])0x0;
        pplStack_b0 = (longlong **)0x0;
        local_1a8[0] = pplVar24;
        local_228 = *(longlong **)(param_1 + 0x138);
        if (local_228 != (longlong *)0x0) {
          *local_228 = *local_228 + 1;
        }
        pplVar27 = (longlong **)DAT_23ed6a4f8;
        if (pplVar24 == (longlong **)0x0) {
          if (iVar7 == 0) {
            iVar7 = (int)plVar3[5];
          }
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pplVar27 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
            pplVar24 = local_1a8[0];
          }
          else {
            pcVar15 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar15;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            pplVar24 = (longlong **)0x0;
          }
          pcVar15 = _PyRuntime_exref;
          pplVar27[2] = (longlong *)0x0;
          pplVar27[3] = plVar3;
          *plVar3 = *plVar3 + 1;
          lVar9 = *(longlong *)(pcVar15 + 0x1f8);
          *(undefined4 *)(pplVar27 + 4) = 0xffffffff;
          lVar9 = *(longlong *)(lVar9 + 0x10);
          *(int *)((longlong)pplVar27 + 0x24) = iVar7;
          plVar13 = *(longlong **)(lVar9 + 0x2e8);
          plVar14 = pplVar27[-1];
          puVar5 = (undefined8 *)plVar13[1];
          *puVar5 = pplVar27 + -2;
          pplVar27[-2] = plVar13;
          pplVar27[-1] = (longlong *)((ulonglong)((uint)plVar14 & 3) | (ulonglong)puVar5);
          plVar13[1] = (longlong)(pplVar27 + -2);
          pplVar26 = pplVar27;
          if ((pplVar24 != (longlong **)0x0) &&
             (*pplVar24 = (longlong *)((longlong)*pplVar24 + -1), *pplVar24 == (longlong *)0x0)) {
            (*(code *)pplVar24[1][6])();
          }
        }
        else {
          pplVar26 = local_1a8[0];
          if (iVar7 != 0) {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pplVar27 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar15 = *(code **)DAT_23ed6a4f8;
              *(undefined8 *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar15;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            pcVar15 = _PyRuntime_exref;
            pplVar27[3] = plVar3;
            *plVar3 = *plVar3 + 1;
            lVar9 = *(longlong *)(pcVar15 + 0x1f8);
            *(undefined4 *)(pplVar27 + 4) = 0xffffffff;
            *(int *)((longlong)pplVar27 + 0x24) = iVar7;
            plVar13 = *(longlong **)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
            plVar14 = pplVar27[-1];
            puVar5 = (undefined8 *)plVar13[1];
            *puVar5 = pplVar27 + -2;
            pplVar27[-2] = plVar13;
            pplVar27[-1] = (longlong *)((ulonglong)((uint)plVar14 & 3) | (ulonglong)puVar5);
            plVar13[1] = (longlong)(pplVar27 + -2);
            pplVar27[2] = (longlong *)pplVar24;
            *pplVar24 = (longlong *)((longlong)*pplVar24 + 1);
            pplVar26 = pplVar27;
            if ((local_1a8[0] != (longlong **)0x0) &&
               (*local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + -1),
               *local_1a8[0] == (longlong *)0x0)) {
              (*(code *)local_1a8[0][1][6])(local_1a8[0]);
            }
          }
        }
        local_1a8[0] = pplVar26;
        if (((longlong **)local_1b8._0_8_ != pplVar25) &&
           ((longlong **)local_1b8._0_8_ != (longlong **)0x0)) {
          FUN_23e91b1b0(param_1,local_1b8,local_1b8 + 8,local_1a8);
        }
        plVar13 = *(longlong **)(local_1b8._8_8_ + 0x28);
        if (local_1a8[0] == pplVar25) {
          pplVar24 = (longlong **)0x0;
        }
        else {
          pplVar24 = local_1a8[0];
          if (local_1a8[0] != (longlong **)0x0) {
            *local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + 1);
          }
        }
        *(longlong ***)(local_1b8._8_8_ + 0x28) = pplVar24;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        plVar13 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = local_1b8._8_8_;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        *(longlong *)local_1b8._0_8_ = *(longlong *)local_1b8._0_8_ + -1;
        if (*(longlong *)local_1b8._0_8_ == 0) {
          (**(code **)(*(longlong *)(local_1b8._0_8_ + 8) + 0x30))();
        }
        if ((local_1a8[0] != (longlong **)0x0) &&
           (*local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + -1),
           *local_1a8[0] == (longlong *)0x0)) {
          (*(code *)local_1a8[0][1][6])();
        }
        local_1a8[0] = (longlong **)0x0;
        local_1b8 = (undefined1  [16])0x0;
        iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                              *(undefined8 *)PyExc_Exception_exref);
        if (iVar7 == 0) {
LAB_23e84caa8:
          pplVar24 = *(longlong ***)(param_1 + 0x138);
          pplStack_b0 = pplVar24;
          if ((pplVar24 == pplVar25) || (pplVar24 == (longlong **)0x0)) {
            pplVar25 = (longlong **)0x0;
            iVar7 = 0x52;
            auVar32 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
            pplVar26 = (longlong **)PyUnicode_FromString("No active exception to reraise");
            pplVar24 = *(longlong ***)(param_1 + 0x138);
            *(longlong **)auVar32 = (longlong *)((longlong)*(longlong **)auVar32 + 1);
            goto LAB_23e84adaf;
          }
          auVar32 = (undefined1  [8])pplVar24[1];
          pplVar25 = (longlong **)pplVar24[5];
          *pplVar24 = (longlong *)((longlong)*pplVar24 + 1);
          *(longlong **)auVar32 = (longlong *)((longlong)*(longlong **)auVar32 + 1);
          pplVar26 = pplVar24;
          if (pplVar25 == (longlong **)0x0) {
            iVar7 = 0;
            *(longlong **)(param_1 + 0x138) = local_228;
          }
          else {
            *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
            if (pplVar25[3] == plVar3) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)((longlong)pplVar25 + 0x24);
            }
            iVar7 = 0;
            *(longlong **)(param_1 + 0x138) = local_228;
          }
LAB_23e84addb:
          local_a8[0] = (longlong **)0x0;
          _local_b8 = (undefined1  [16])0x0;
          *pplVar24 = (longlong *)((longlong)*pplVar24 + -1);
          if (*pplVar24 == (longlong *)0x0) {
            (*(code *)pplVar24[1][6])();
          }
        }
        else {
          plVar13 = *(longlong **)(param_1 + 0x138);
          *plVar13 = *plVar13 + 1;
          local_208 = (undefined *)FUN_23a3a0d40(DAT_23ed6cf28);
          plVar14 = DAT_23eedbda8;
          lVar9 = *(longlong *)(param_1 + 0x10);
          pplVar24 = *(longlong ***)(lVar9 + 0xe30);
          if (pplVar24 == (longlong **)0x0) {
            pplVar24 = (longlong **)FUN_23e916a20(PyTuple_Type_exref,4);
          }
          else {
            plVar17 = pplVar24[3];
            *(int *)(lVar9 + 0xec4) = *(int *)(lVar9 + 0xec4) + -1;
            *(longlong **)(lVar9 + 0xe30) = plVar17;
            *pplVar24 = (longlong *)0x1;
          }
          pcVar15 = _PyRuntime_exref;
          pplVar24[6] = (longlong *)0x0;
          *(undefined1 (*) [16])(pplVar24 + 4) = (undefined1  [16])0x0;
          plVar17 = *(longlong **)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
          plVar12 = pplVar24[-1];
          puVar5 = (undefined8 *)plVar17[1];
          *puVar5 = pplVar24 + -2;
          pplVar24[-2] = plVar17;
          pplVar24[-1] = (longlong *)((ulonglong)((uint)plVar12 & 3) | (ulonglong)puVar5);
          plVar17[1] = (longlong)(pplVar24 + -2);
          *plVar14 = *plVar14 + 1;
          pplVar24[3] = plVar14;
          plVar14 = (longlong *)FUN_23e8bf9b0(plVar10,DAT_23ed6ccf8);
          pplVar27 = pplVar24;
          if (plVar14 == (longlong *)0x0) {
LAB_23e84ad0b:
            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
            iVar7 = 0xf1;
            local_a8[0] = *(longlong ***)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *pplVar27 = (longlong *)((longlong)*pplVar27 + -1);
            auVar32 = local_b8;
            pplVar26 = pplStack_b0;
            pplVar25 = local_a8[0];
            if (*pplVar27 == (longlong *)0x0) {
              (*(code *)pplVar27[1][6])(pplVar27);
              auVar32 = local_b8;
              pplVar26 = pplStack_b0;
              pplVar25 = local_a8[0];
            }
          }
          else {
            pcVar15 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar17 == (longlong *)0x0) goto LAB_23e84b230;
              *plVar17 = *plVar17 + 1;
              DAT_23ed6a4c0 = plVar17;
            }
            local_98 = plVar14;
            pcStack_90 = pcVar15;
            plVar17 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_98);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar17 == (longlong *)0x0) goto LAB_23e84ad0b;
            pplVar24[4] = plVar17;
            plVar12 = DAT_23eedbdb0;
            plVar17 = DAT_23ed6a4c0;
            *DAT_23eedbdb0 = *DAT_23eedbdb0 + 1;
            pplVar24[5] = plVar12;
            pcVar15 = DAT_23ed6cd28;
            if (plVar17 == (longlong *)0x0) {
              plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar17 == (longlong *)0x0) {
LAB_23e84b230:
                iVar7 = (int)pplVar24;
                PyErr_PrintEx(0,0);
                Py_Exit(1);
                plVar12 = plVar10;
LAB_23e84b248:
                pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                pplVar27 = local_1a8[0];
                do {
                  pcVar15 = _PyRuntime_exref;
                  pplVar24[2] = (longlong *)0x0;
                  pplVar24[3] = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                  *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                  lVar9 = *(longlong *)(lVar9 + 0x10);
                  *(int *)((longlong)pplVar24 + 0x24) = iVar7;
                  plVar10 = *(longlong **)(lVar9 + 0x2e8);
                  plVar13 = pplVar24[-1];
                  puVar5 = (undefined8 *)plVar10[1];
                  *puVar5 = pplVar24 + -2;
                  pplVar24[-2] = plVar10;
                  pplVar24[-1] = (longlong *)((ulonglong)((uint)plVar13 & 3) | (ulonglong)puVar5);
                  plVar10[1] = (longlong)(pplVar24 + -2);
                  plVar10 = plVar12;
                  pplVar26 = pplVar24;
                  if ((pplVar27 != (longlong **)0x0) &&
                     (*pplVar27 = (longlong *)((longlong)*pplVar27 + -1),
                     *pplVar27 == (longlong *)0x0)) {
                    (*(code *)pplVar27[1][6])();
                  }
LAB_23e84a1c3:
                  local_1a8[0] = pplVar26;
                  if (((longlong **)local_1b8._0_8_ != pplVar25) &&
                     ((longlong **)local_1b8._0_8_ != (longlong **)0x0)) {
                    FUN_23e91b1b0(param_1,local_1b8,local_1b8 + 8,local_1a8);
                  }
                  plVar13 = *(longlong **)(local_1b8._8_8_ + 0x28);
                  if (local_1a8[0] == pplVar25) {
                    pplVar24 = (longlong **)0x0;
                  }
                  else {
                    pplVar24 = local_1a8[0];
                    if (local_1a8[0] != (longlong **)0x0) {
                      *local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + 1);
                    }
                  }
                  *(longlong ***)(local_1b8._8_8_ + 0x28) = pplVar24;
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  plVar13 = *(longlong **)(param_1 + 0x138);
                  *(undefined8 *)(param_1 + 0x138) = local_1b8._8_8_;
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  *(longlong *)local_1b8._0_8_ = *(longlong *)local_1b8._0_8_ + -1;
                  if (*(longlong *)local_1b8._0_8_ == 0) {
                    (**(code **)(*(longlong *)(local_1b8._0_8_ + 8) + 0x30))();
                  }
                  if ((local_1a8[0] != (longlong **)0x0) &&
                     (*local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + -1),
                     *local_1a8[0] == (longlong *)0x0)) {
                    (*(code *)local_1a8[0][1][6])();
                  }
                  local_1a8[0] = (longlong **)0x0;
                  local_1b8 = (undefined1  [16])0x0;
                  iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                        *(undefined8 *)PyExc_Exception_exref);
                  local_228 = plVar14;
                  if (iVar7 == 0) goto LAB_23e84caa8;
                  plVar13 = *(longlong **)(param_1 + 0x138);
                  *plVar13 = *plVar13 + 1;
                  uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
                  plVar17 = DAT_23eedbda8;
                  lVar9 = *(longlong *)(param_1 + 0x10);
                  pplVar25 = *(longlong ***)(lVar9 + 0xe30);
                  if (pplVar25 == (longlong **)0x0) {
                    pplVar25 = (longlong **)FUN_23e916a20(PyTuple_Type_exref,4);
                  }
                  else {
                    plVar12 = pplVar25[3];
                    *(int *)(lVar9 + 0xec4) = *(int *)(lVar9 + 0xec4) + -1;
                    *(longlong **)(lVar9 + 0xe30) = plVar12;
                    *pplVar25 = (longlong *)0x1;
                  }
                  pcVar15 = _PyRuntime_exref;
                  pplVar25[6] = (longlong *)0x0;
                  *(undefined1 (*) [16])(pplVar25 + 4) = (undefined1  [16])0x0;
                  plVar12 = *(longlong **)
                             (*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
                  plVar20 = pplVar25[-1];
                  puVar5 = (undefined8 *)plVar12[1];
                  *puVar5 = pplVar25 + -2;
                  pplVar25[-2] = plVar12;
                  pplVar25[-1] = (longlong *)((ulonglong)((uint)plVar20 & 3) | (ulonglong)puVar5);
                  plVar12[1] = (longlong)(pplVar25 + -2);
                  *plVar17 = *plVar17 + 1;
                  pplVar25[3] = plVar17;
                  plVar17 = (longlong *)FUN_23e8bf9b0(plVar10,DAT_23ed6ccf8);
                  pcVar15 = DAT_23ed6cd28;
                  pplVar27 = pplVar25;
                  if (plVar17 == (longlong *)0x0) goto LAB_23e84ad0b;
                  pplVar24 = &DAT_23ed6a4c0;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar12 == (longlong *)0x0) goto LAB_23e84b230;
                    *plVar12 = *plVar12 + 1;
                    DAT_23ed6a4c0 = plVar12;
                  }
                  pcStack_90 = pcVar15;
                  local_98 = plVar17;
                  plVar12 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_98);
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e84ad0b;
                  pplVar25[4] = plVar12;
                  plVar12 = DAT_23eedbdb0;
                  plVar17 = DAT_23ed6a4c0;
                  *DAT_23eedbdb0 = *DAT_23eedbdb0 + 1;
                  pplVar25[5] = plVar12;
                  pcVar15 = DAT_23ed6cd28;
                  if (plVar17 == (longlong *)0x0) {
                    plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar17 == (longlong *)0x0) goto LAB_23e84b230;
                    *plVar17 = *plVar17 + 1;
                    DAT_23ed6a4c0 = plVar17;
                  }
                  pcStack_90 = pcVar15;
                  local_98 = plVar13;
                  plVar17 = (longlong *)FUN_23e94ed00(param_1,plVar17,&local_98);
                  if (plVar17 == (longlong *)0x0) goto LAB_23e84ad0b;
                  pplVar25[6] = plVar17;
                  plVar17 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pplVar25);
                  *pplVar25 = (longlong *)((longlong)*pplVar25 + -1);
                  if (*pplVar25 == (longlong *)0x0) {
                    (*(code *)pplVar25[1][6])(pplVar25);
                  }
                  if (plVar17 == (longlong *)0x0) goto LAB_23e84b1d0;
                  *(undefined4 *)(plVar3 + 5) = 0xf1;
                  plVar12 = (longlong *)FUN_23e914090(param_1,uVar22,plVar17);
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e84b1d0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  plVar17 = (longlong *)FUN_23e8c5d90(plVar2,DAT_23ed6ccf8);
                  if (plVar17 == (longlong *)0x0) {
LAB_23e84b200:
                    auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                    iVar7 = 0xf2;
                    pplVar25 = *(longlong ***)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar26 = *(longlong ***)(param_1 + 0x68);
                    goto LAB_23e84ad70;
                  }
                  iVar7 = FUN_23e97c060(plVar10,plVar17);
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if (iVar7 == -1) goto LAB_23e84b200;
                  if (iVar7 == 1) {
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbda0;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) {
                      iVar7 = 0xf3;
                      FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                      auVar32 = local_b8;
                      pplVar26 = pplStack_b0;
                      pplVar25 = local_a8[0];
                      goto LAB_23e84ad70;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xf3;
                    plVar17 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar17 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      iVar7 = 0xf3;
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pplVar26 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e84ad70;
                    }
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                    }
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  plVar13 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
LAB_23e84a548:
                  lVar9 = *(longlong *)(param_1 + 0x10);
                  if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                       (*(int *)(lVar9 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0))
                     && (auVar32 = *(undefined1 (*) [8])(param_1 + 0x60),
                        auVar32 != (undefined1  [8])0x0)) {
LAB_23e84a706:
                    pplVar25 = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    iVar7 = 0x51;
                    pplVar26 = *(longlong ***)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a740;
                  }
                  if (*(int *)(lVar9 + 0x68) == 0) {
                    plVar13 = *(longlong **)(param_1 + 0x90);
                  }
                  else {
                    PyEval_SaveThread();
                    PyEval_AcquireThread(param_1);
                    plVar13 = *(longlong **)(param_1 + 0x90);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    plVar17 = *(longlong **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x90) = 0;
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    *(longlong **)(param_1 + 0x60) = plVar13;
                    *plVar13 = *plVar13 + 1;
                    *(undefined8 *)(param_1 + 0x68) = 0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                      (**(code **)(plVar17[1] + 0x30))();
                    }
                    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                    goto LAB_23e84a706;
                  }
LAB_23e84895a:
                  plVar12 = (longlong *)(**(code **)(plVar11[1] + 0xe0))();
                  if (plVar12 == (longlong *)0x0) {
                    cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                    if (cVar6 != '\0') {
                      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0))
                      {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      goto LAB_23e84c9cf;
                    }
                    auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplVar26 = *(longlong ***)(param_1 + 0x68);
                    pplVar25 = *(longlong ***)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    if (plVar10 == (longlong *)0x0) goto LAB_23e84cdc0;
                    iVar7 = 0x51;
                    goto LAB_23e84a740;
                  }
                  if (plVar10 == (longlong *)0x0) {
                    *plVar12 = *plVar12 + 1;
                  }
                  else {
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    *plVar12 = *plVar12 + 1;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                  }
                  lVar9 = FUN_23e8daec0();
                  plVar10 = plVar12;
                  if (lVar9 == 0) {
                    iVar7 = 0x58;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbf0);
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0x58;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a160;
                  }
                  if (plVar1 == (longlong *)0x0) {
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    pplStack_b0 = (longlong **)
                                  PyUnicode_FromFormat
                                            ("cannot access local variable \'%U\' where it is not associated with a value"
                                             ,DAT_23eedbbf8);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    local_b8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                    *(longlong **)local_b8 = (longlong *)((longlong)*(longlong **)local_b8 + 1);
                    local_a8[0] = (longlong **)0x0;
                    if (local_b8 != (undefined1  [8])pplVar25) {
                      FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
                    }
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pplStack_b0);
LAB_23e84a15a:
                    iVar7 = 0x58;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x58;
                  plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if (plVar14 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a15a;
                  }
                  iVar7 = FUN_23a35f020();
                  lVar9 = *plVar14 + -1;
                  if (iVar7 == -1) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar14 = lVar9;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    if (lVar9 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                      pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    }
                    goto LAB_23e84a15a;
                  }
                  *plVar14 = lVar9;
                  if (lVar9 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (iVar7 != 0) {
                    lVar9 = FUN_23e8daec0();
                    if (lVar9 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc00);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e84ac90:
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        lVar9 = FUN_23e8dad70();
                        if (lVar9 == 0) {
                          FUN_23e915740(param_1,local_b8,DAT_23eedbc08);
                          *plVar13 = *plVar13 + -1;
                          lVar9 = *plVar13;
                        }
                        else {
                          pcVar15 = (code *)FUN_23e8bc2f0(lVar9,DAT_23eedbc10);
                          if (pcVar15 != (code *)0x0) {
                            *(undefined4 *)(plVar3 + 5) = 0x59;
                            local_98 = plVar1;
                            pcStack_90 = pcVar15;
                            plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))();
                            }
                            *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                            if (*(longlong *)pcVar15 == 0) {
                              (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
                            }
                            if (plVar14 == (longlong *)0x0) goto LAB_23e84ac90;
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            lVar16 = FUN_23e8dac20();
                            lVar9 = DAT_23eedbc28;
                            uVar22 = DAT_23eedbc20;
                            if (lVar16 == 0) {
                              FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                            }
                            else {
                              *(undefined4 *)(plVar3 + 5) = 0x5a;
                              plVar13 = (longlong *)
                                        FUN_23e915840(param_1,lVar16,uVar22,
                                                      *(undefined8 *)(lVar9 + 0x18));
                              if (plVar13 != (longlong *)0x0) {
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))();
                                }
                                goto LAB_23e848a4e;
                              }
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            iVar7 = 0x5a;
                            pplVar25 = (longlong **)_Py_NoneStruct_exref;
                            goto LAB_23e84a160;
                          }
                          local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                          local_a8[0] = *(longlong ***)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar13 = *plVar13 + -1;
                          lVar9 = *plVar13;
                        }
                        if (lVar9 == 0) {
                          (**(code **)(plVar13[1] + 0x30))();
                        }
                      }
                    }
                    iVar7 = 0x59;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
LAB_23e848a4e:
                  lVar9 = FUN_23e8daec0();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e84ac5b:
                    iVar7 = 0x5d;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc00);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84ac30:
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84ac5b;
                  }
                  lVar9 = FUN_23e8dad70();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc08);
                    *plVar13 = *plVar13 + -1;
                    lVar9 = *plVar13;
joined_r0x00023e84cc3e:
                    if (lVar9 == 0) {
                      (**(code **)(plVar13[1] + 0x30))();
                    }
                    goto LAB_23e84ac5b;
                  }
                  pcVar15 = (code *)FUN_23e8bc2f0(lVar9,DAT_23eedbc30);
                  if (pcVar15 == (code *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    lVar9 = *plVar13;
                    goto joined_r0x00023e84cc3e;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x5d;
                  local_98 = plVar1;
                  pcStack_90 = pcVar15;
                  plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
                  }
                  if (plVar14 == (longlong *)0x0) goto LAB_23e84ac30;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  lVar16 = FUN_23e8dac20();
                  lVar9 = DAT_23eedbc38;
                  uVar22 = DAT_23eedbc20;
                  if (lVar16 == 0) {
                    iVar7 = 0x5e;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x5e;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0x5e;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a160;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  lVar9 = FUN_23e8daec0();
                  if (lVar9 == 0) {
                    iVar7 = 0x61;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc40);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84cb30:
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0x61;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x61;
                  plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if (plVar14 == (longlong *)0x0) goto LAB_23e84cb30;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  lVar16 = FUN_23e8dac20();
                  lVar9 = DAT_23eedbc38;
                  uVar22 = DAT_23eedbc20;
                  if (lVar16 == 0) {
                    iVar7 = 0x62;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x62;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0x62;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84a160;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  lVar9 = FUN_23e8daec0();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e84dac6:
                    local_220 = local_280;
                    uVar35 = 0x6b;
LAB_23e84d16a:
                    pplVar25 = local_a8[0];
                    local_f8._8_8_ = pplStack_b0;
                    local_f8._0_8_ = local_b8;
                    local_a8[0] = (longlong **)0x0;
                    plVar13 = *(longlong **)(param_1 + 0x138);
                    local_b8 = (undefined1  [8])0x0;
                    pplStack_b0 = (longlong **)0x0;
                    local_e8[0] = pplVar25;
                    if (plVar13 != (longlong *)0x0) {
                      *plVar13 = *plVar13 + 1;
                    }
                    pplVar24 = (longlong **)DAT_23ed6a4f8;
                    if (pplVar25 == (longlong **)0x0) {
                      if (DAT_23ed6a4f8 == (code *)0x0) {
                        pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        pcVar15 = *(code **)DAT_23ed6a4f8;
                        *(undefined8 *)DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = pcVar15;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      pcVar15 = _PyRuntime_exref;
                      pplVar24[2] = (longlong *)0x0;
                      pplVar24[3] = plVar3;
                      *plVar3 = *plVar3 + 1;
                      lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                      *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                      lVar9 = *(longlong *)(lVar9 + 0x10);
                      *(undefined4 *)((longlong)pplVar24 + 0x24) = uVar35;
                      plVar14 = *(longlong **)(lVar9 + 0x2e8);
                      plVar17 = pplVar24[-1];
                      plVar20 = (longlong *)plVar14[1];
                      *plVar20 = (longlong)(pplVar24 + -2);
                      pplVar24[-2] = plVar14;
                      pplVar24[-1] = (longlong *)
                                     ((ulonglong)((uint)plVar17 & 3) | (ulonglong)plVar20);
                      plVar14[1] = (longlong)(pplVar24 + -2);
                      if ((local_e8[0] != (longlong **)0x0) &&
                         (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                         *local_e8[0] == (longlong *)0x0)) {
                        (*(code *)local_e8[0][1][6])(local_e8[0]);
                      }
                    }
                    else {
                      if (DAT_23ed6a4f8 == (code *)0x0) {
                        pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        pcVar15 = *(code **)DAT_23ed6a4f8;
                        *(undefined8 *)DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = pcVar15;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      pcVar15 = _PyRuntime_exref;
                      pplVar24[3] = plVar3;
                      *plVar3 = *plVar3 + 1;
                      lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                      *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                      *(undefined4 *)((longlong)pplVar24 + 0x24) = uVar35;
                      plVar14 = *(longlong **)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
                      plVar17 = pplVar24[-1];
                      plVar20 = (longlong *)plVar14[1];
                      *plVar20 = (longlong)(pplVar24 + -2);
                      pplVar24[-2] = plVar14;
                      pplVar24[-1] = (longlong *)
                                     ((ulonglong)((uint)plVar17 & 3) | (ulonglong)plVar20);
                      plVar14[1] = (longlong)(pplVar24 + -2);
                      pplVar24[2] = (longlong *)pplVar25;
                      *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                      if ((local_e8[0] != (longlong **)0x0) &&
                         (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                         *local_e8[0] == (longlong *)0x0)) {
                        (*(code *)local_e8[0][1][6])();
                      }
                    }
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    local_e8[0] = pplVar24;
                    if (((code *)local_f8._0_8_ != (code *)0x0) &&
                       ((code *)local_f8._0_8_ != _Py_NoneStruct_exref)) {
                      FUN_23e91b1b0(param_1,local_f8,local_f8 + 8,local_e8);
                    }
                    plVar14 = *(longlong **)(local_f8._8_8_ + 0x28);
                    if (local_e8[0] == pplVar25) {
                      pplVar24 = (longlong **)0x0;
                    }
                    else {
                      pplVar24 = local_e8[0];
                      if (local_e8[0] != (longlong **)0x0) {
                        *local_e8[0] = (longlong *)((longlong)*local_e8[0] + 1);
                      }
                    }
                    *(longlong ***)(local_f8._8_8_ + 0x28) = pplVar24;
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    plVar14 = *(longlong **)(param_1 + 0x138);
                    *(undefined8 *)(param_1 + 0x138) = local_f8._8_8_;
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    *(longlong *)local_f8._0_8_ = *(longlong *)local_f8._0_8_ + -1;
                    if (*(longlong *)local_f8._0_8_ == 0) {
                      (**(code **)(*(longlong *)(local_f8._0_8_ + 8) + 0x30))();
                    }
                    if ((local_e8[0] != (longlong **)0x0) &&
                       (*local_e8[0] = (longlong *)((longlong)*local_e8[0] + -1),
                       *local_e8[0] == (longlong *)0x0)) {
                      (*(code *)local_e8[0][1][6])();
                    }
                    local_e8[0] = (longlong **)0x0;
                    local_f8 = (undefined1  [16])0x0;
                    iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                   (*(longlong *)(param_1 + 0x138) + 8));
                    if (iVar7 == 0) {
                      pplVar24 = *(longlong ***)(param_1 + 0x138);
                      pplStack_b0 = pplVar24;
                      if ((pplVar24 == (longlong **)0x0) || (pplVar24 == pplVar25)) {
                        iVar7 = 0x69;
                        pplVar27 = *(longlong ***)PyExc_RuntimeError_exref;
                        pplVar26 = (longlong **)
                                   PyUnicode_FromString("No active exception to reraise");
                        *pplVar27 = (longlong *)((longlong)*pplVar27 + 1);
LAB_23e84db24:
                        pplVar24 = *(longlong ***)(param_1 + 0x138);
                        pplVar31 = (longlong **)0x0;
                        *(longlong **)(param_1 + 0x138) = plVar13;
                        if (pplVar24 != (longlong **)0x0) goto LAB_23e84d916;
                        pplVar31 = (longlong **)0x0;
                      }
                      else {
                        pplVar27 = (longlong **)pplVar24[1];
                        pplVar31 = (longlong **)pplVar24[5];
                        *pplVar24 = (longlong *)((longlong)*pplVar24 + 1);
                        *pplVar27 = (longlong *)((longlong)*pplVar27 + 1);
                        iVar7 = 0;
                        pplVar26 = pplVar24;
                        if (pplVar31 == (longlong **)0x0) goto LAB_23e84db24;
                        *pplVar31 = (longlong *)((longlong)*pplVar31 + 1);
                        if (pplVar31[3] == plVar3) {
                          *(undefined4 *)(plVar3 + 5) = *(undefined4 *)((longlong)pplVar31 + 0x24);
                        }
                        *(longlong **)(param_1 + 0x138) = plVar13;
LAB_23e84d916:
                        local_a8[0] = (longlong **)0x0;
                        _local_b8 = (undefined1  [16])0x0;
                        *pplVar24 = (longlong *)((longlong)*pplVar24 + -1);
                        if (*pplVar24 == (longlong *)0x0) {
                          (*(code *)pplVar24[1][6])();
                        }
                      }
                      local_280 = local_220;
                      local_a8[0] = pplVar31;
                      local_b8 = (undefined1  [8])pplVar27;
                      pplStack_b0 = pplVar26;
                      goto LAB_23e84a160;
                    }
                    plVar14 = *(longlong **)(param_1 + 0x138);
                    lVar9 = *plVar14;
                    if (lVar9 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                      plVar14 = *(longlong **)(param_1 + 0x138);
                      *(longlong **)(param_1 + 0x138) = plVar13;
                      if (plVar14 == (longlong *)0x0) goto LAB_23e848cbb;
                      lVar9 = *plVar14;
                    }
                    else {
                      *(longlong **)(param_1 + 0x138) = plVar13;
                    }
                    *plVar14 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x6b;
                    local_220 = (longlong *)FUN_23e91bfe0(param_1,lVar9,DAT_23eedbc48);
                    if (local_220 == (longlong *)0x0) {
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84dac6;
                    }
                    if ((local_280 != (longlong *)0x0) &&
                       (lVar9 = *local_280, *local_280 = lVar9 + -1, lVar9 + -1 == 0)) {
                      (**(code **)(local_280[1] + 0x30))(local_280);
                    }
                    iVar7 = FUN_23a35f020(local_220);
                    if (iVar7 == -1) {
LAB_23e84d139:
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      uVar35 = 0x6c;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e84d16a;
                    }
                    if (iVar7 != 0) {
                      iVar7 = FUN_23e983ac0(local_220,plVar1);
                      if (iVar7 == -1) goto LAB_23e84d139;
                      if (iVar7 != 1) goto LAB_23e848cbb;
                      lVar9 = FUN_23e8daff0();
                      if (lVar9 == 0) {
                        FUN_23e915740(param_1,local_b8,DAT_23eedbbb0);
                        pplVar25 = local_a8[0];
                        auVar32 = local_b8;
                        pplVar24 = pplStack_b0;
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x6d;
                        plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,DAT_23eedbbb8,local_220);
                        if (plVar13 != (longlong *)0x0) {
                          plVar14 = (longlong *)FUN_23a388310();
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar14 != (longlong *)0x0) {
                            plVar13 = (longlong *)FUN_23a3c1d30(param_1,local_b8,plVar14,0,2);
                            if (plVar13 == (longlong *)0x0) {
                              plVar17 = (longlong *)0x0;
                              *plVar14 = *plVar14 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar14 != 0) goto LAB_23e84e23e;
LAB_23e84ea2a:
                              pplStack_b0 = (longlong **)0x0;
                              local_b8 = (undefined1  [8])0x0;
                              local_a8[0] = (longlong **)0x0;
                              FUN_23a334bc0(plVar14);
                              local_a8[0] = (longlong **)0x0;
                              local_b8 = (undefined1  [8])0x0;
                              pplStack_b0 = (longlong **)0x0;
                              if (plVar13 != (longlong *)0x0) {
LAB_23e84e86c:
                                pplStack_b0 = (longlong **)0x0;
                                local_b8 = (undefined1  [8])0x0;
                                local_a8[0] = (longlong **)0x0;
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                              }
                              if ((plVar17 != (longlong *)0x0) &&
                                 (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                                FUN_23a334bc0(plVar17);
                              }
                              goto LAB_23e84e23e;
                            }
                            plVar17 = (longlong *)FUN_23a3c1d30(param_1,local_b8,plVar14,1,2);
                            if ((plVar17 == (longlong *)0x0) ||
                               (cVar6 = FUN_23a3884a0(param_1,local_b8,plVar14,2), cVar6 == '\0')) {
                              *plVar14 = *plVar14 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar14 == 0) goto LAB_23e84ea2a;
                              goto LAB_23e84e86c;
                            }
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                            }
                            *plVar13 = *plVar13 + 1;
                            if ((local_260 != (longlong *)0x0) &&
                               (lVar9 = *local_260, *local_260 = lVar9 + -1, lVar9 + -1 == 0)) {
                              FUN_23a334bc0(local_260);
                            }
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0(plVar13);
                            }
                            *plVar17 = *plVar17 + 1;
                            if ((local_278 != (longlong *)0x0) &&
                               (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0)) {
                              FUN_23a334bc0(local_278);
                            }
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              FUN_23a334bc0(plVar17);
                            }
                            lVar9 = FUN_23e8daff0();
                            local_260 = plVar13;
                            if (lVar9 == 0) {
                              FUN_23e915740(param_1,local_b8,DAT_23eedbbb0);
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                            }
                            else {
                              plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbb8);
                              if (plVar14 != (longlong *)0x0) {
                                *(undefined4 *)(plVar3 + 5) = 0x70;
                                plVar20 = (longlong *)FUN_23e914090(param_1,plVar14);
                                *plVar14 = *plVar14 + -1;
                                if (*plVar14 == 0) {
                                  FUN_23a334bc0(plVar14);
                                }
                                if (plVar20 != (longlong *)0x0) {
                                  plVar14 = (longlong *)FUN_23a388310(plVar20);
                                  *plVar20 = *plVar20 + -1;
                                  if (*plVar20 == 0) {
                                    FUN_23a334bc0(plVar20);
                                  }
                                  if (plVar14 != (longlong *)0x0) {
                                    pcVar15 = (code *)FUN_23a3c1d30(param_1,local_b8,plVar14,0,2);
                                    if (pcVar15 == (code *)0x0) {
                                      *plVar14 = *plVar14 + -1;
                                      local_278 = (longlong *)0x0;
                                      pplVar25 = local_a8[0];
                                      auVar32 = local_b8;
                                      pplVar24 = pplStack_b0;
                                      if (*plVar14 != 0) goto LAB_23e84ef31;
LAB_23e8528ea:
                                      pplStack_b0 = (longlong **)0x0;
                                      local_b8 = (undefined1  [8])0x0;
                                      local_a8[0] = (longlong **)0x0;
                                      FUN_23a334bc0(plVar14);
                                      local_a8[0] = (longlong **)0x0;
                                      local_b8 = (undefined1  [8])0x0;
                                      pplStack_b0 = (longlong **)0x0;
                                      if (pcVar15 != (code *)0x0) {
LAB_23e85290d:
                                        pplStack_b0 = (longlong **)0x0;
                                        local_b8 = (undefined1  [8])0x0;
                                        local_a8[0] = (longlong **)0x0;
                                        *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                                        if (*(longlong *)pcVar15 == 0) {
                                          FUN_23a334bc0(pcVar15);
                                        }
                                      }
                                      if ((local_278 != (longlong *)0x0) &&
                                         (lVar9 = *local_278, *local_278 = lVar9 + -1,
                                         lVar9 + -1 == 0)) {
                                        FUN_23a334bc0(local_278);
                                      }
                                      goto LAB_23e84ef31;
                                    }
                                    local_278 = (longlong *)
                                                FUN_23a3c1d30(param_1,local_b8,plVar14,1,2);
                                    if ((local_278 == (longlong *)0x0) ||
                                       (cVar6 = FUN_23a3884a0(param_1,local_b8,plVar14),
                                       cVar6 == '\0')) {
                                      *plVar14 = *plVar14 + -1;
                                      pplVar25 = local_a8[0];
                                      auVar32 = local_b8;
                                      pplVar24 = pplStack_b0;
                                      if (*plVar14 == 0) goto LAB_23e8528ea;
                                      goto LAB_23e85290d;
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      FUN_23a334bc0(plVar14);
                                    }
                                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                                    if ((local_268 != (code *)0x0) &&
                                       (lVar9 = *(longlong *)local_268,
                                       *(longlong *)local_268 = lVar9 + -1, lVar9 + -1 == 0)) {
                                      FUN_23a334bc0(local_268);
                                    }
                                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                                    if (*(longlong *)pcVar15 == 0) {
                                      FUN_23a334bc0(pcVar15);
                                    }
                                    *local_278 = *local_278 + 1;
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    lVar9 = *local_278;
                                    *local_278 = lVar9 + -1;
                                    if (lVar9 + -1 == 0) {
                                      FUN_23a334bc0(local_278);
                                    }
                                    iVar7 = FUN_23e983ac0(plVar13,pcVar15);
                                    local_268 = pcVar15;
                                    if (iVar7 == -1) {
                                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar35 = 0x72;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                      goto LAB_23e84d16a;
                                    }
                                    if (iVar7 != 1) goto LAB_23e848cbb;
                                    uVar22 = FUN_23e9373d0();
                                    plVar14 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                                    if (plVar14 != (longlong *)0x0) {
                                      plVar17 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbc58);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      if (plVar17 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar3 + 5) = 0x75;
                                        local_88 = _Py_TrueStruct_exref;
                                        local_98 = plVar13;
                                        pcStack_90 = pcVar15;
                                        plVar14 = (longlong *)
                                                  FUN_23e9578c0(param_1,plVar17,DAT_23eedbc60,
                                                                &local_98);
                                        *plVar17 = *plVar17 + -1;
                                        if (*plVar17 == 0) {
                                          FUN_23a334bc0(plVar17);
                                        }
                                        if (plVar14 != (longlong *)0x0) {
                                          if ((local_248 != (longlong *)0x0) &&
                                             (lVar9 = *local_248, *local_248 = lVar9 + -1,
                                             lVar9 + -1 == 0)) {
                                            FUN_23a334bc0(local_248);
                                          }
                                          iVar7 = FUN_23a35f020(plVar14);
                                          local_248 = plVar14;
                                          if (iVar7 == -1) {
                                            local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar35 = 0x79;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                            goto LAB_23e84d16a;
                                          }
                                          if (iVar7 == 0) goto LAB_23e848cbb;
                                          lVar9 = FUN_23e8daec0();
                                          if (lVar9 == 0) {
LAB_23e850825:
                                            FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e8507db:
                                            local_c8 = local_a8[0];
                                            local_a8[0] = (longlong **)0x0;
                                            local_d8 = (longlong **)local_b8;
                                            pplStack_d0 = pplStack_b0;
                                            local_b8 = (undefined1  [8])0x0;
                                            pplStack_b0 = (longlong **)0x0;
                                            FUN_23a35d6b0(&local_d8);
                                          }
                                          else {
                                            plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc68)
                                            ;
                                            if (plVar14 == (longlong *)0x0) {
LAB_23e8507b2:
                                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e8507db;
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x7c;
                                            plVar17 = (longlong *)
                                                      FUN_23e914090(param_1,plVar14,plVar1);
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            if (plVar17 == (longlong *)0x0) goto LAB_23e8507b2;
                                            *plVar17 = *plVar17 + -1;
                                            if (*plVar17 == 0) {
                                              FUN_23a334bc0(plVar17);
                                            }
                                            lVar9 = FUN_23e8daec0();
                                            if (lVar9 == 0) goto LAB_23e850825;
                                            plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc70)
                                            ;
                                            if (plVar14 == (longlong *)0x0) goto LAB_23e8507b2;
                                            *(undefined4 *)(plVar3 + 5) = 0x7d;
                                            plVar17 = (longlong *)
                                                      FUN_23e914090(param_1,plVar14,plVar1);
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            if (plVar17 == (longlong *)0x0) goto LAB_23e8507b2;
                                            *plVar17 = *plVar17 + -1;
                                            if (*plVar17 == 0) {
                                              FUN_23a334bc0(plVar17);
                                            }
                                          }
                                          uVar22 = FUN_23e9373d0();
                                          plVar14 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                                          if (plVar14 != (longlong *)0x0) {
                                            plVar17 = (longlong *)
                                                      FUN_23e8bc2f0(plVar14,DAT_23eedbc58);
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            if (plVar17 != (longlong *)0x0) {
                                              *(undefined4 *)(plVar3 + 5) = 0x82;
                                              local_88 = _Py_FalseStruct_exref;
                                              local_98 = plVar13;
                                              pcStack_90 = pcVar15;
                                              plVar13 = (longlong *)
                                                        FUN_23e9578c0(param_1,plVar17,DAT_23eedbc60,
                                                                      &local_98);
                                              *plVar17 = *plVar17 + -1;
                                              if (*plVar17 == 0) {
                                                FUN_23a334bc0(plVar17);
                                              }
                                              if (plVar13 != (longlong *)0x0) {
                                                *plVar13 = *plVar13 + -1;
                                                if (*plVar13 == 0) {
                                                  FUN_23a334bc0(plVar13);
                                                }
                                                goto LAB_23e848cbb;
                                              }
                                            }
                                          }
                                          local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                          uVar35 = 0x82;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                          goto LAB_23e84d16a;
                                        }
                                      }
                                    }
                                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar35 = 0x75;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                                    goto LAB_23e84d16a;
                                  }
                                }
                              }
                              pplVar25 = *(longlong ***)(param_1 + 0x70);
                              auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pplVar24 = *(longlong ***)(param_1 + 0x68);
                            }
LAB_23e84ef31:
                            uVar35 = 0x70;
                            local_278 = plVar17;
                            local_a8[0] = pplVar25;
                            local_b8 = auVar32;
                            pplStack_b0 = pplVar24;
                            goto LAB_23e84d16a;
                          }
                        }
                        pplVar25 = *(longlong ***)(param_1 + 0x70);
                        auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        pplVar24 = *(longlong ***)(param_1 + 0x68);
                      }
LAB_23e84e23e:
                      uVar35 = 0x6d;
                      local_a8[0] = pplVar25;
                      local_b8 = auVar32;
                      pplStack_b0 = pplVar24;
                      goto LAB_23e84d16a;
                    }
                  }
LAB_23e848cbb:
                  lVar16 = FUN_23e8dac20();
                  lVar9 = DAT_23eedbc38;
                  uVar22 = DAT_23eedbc20;
                  local_280 = local_220;
                  if (lVar16 == 0) {
                    iVar7 = 0x89;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x89;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0x89;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    goto LAB_23e84a160;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if ((DAT_23ed8fb50 == 0) &&
                     (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0))
                  goto LAB_23e84ddfa;
                  plVar13 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc78);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84d109:
                    auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplVar25 = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e8495af:
                    pplStack_b0 = pplVar24;
                    local_b8 = auVar32;
                    local_a8[0] = pplVar25;
                    local_128 = local_a8[0];
                    local_a8[0] = (longlong **)0x0;
                    local_138 = (longlong **)local_b8;
                    pplStack_130 = pplStack_b0;
                    local_b8 = (undefined1  [8])0x0;
                    pplStack_b0 = (longlong **)0x0;
                    FUN_23a35d6b0(&local_138);
                  }
                  else {
                    if ((DAT_23ed8fb50 == 0) &&
                       (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                      DAT_23ed8fb50 = 0;
                      goto LAB_23e84ddfa;
                    }
                    plVar14 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc80);
                    if (plVar14 == (longlong *)0x0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                        pplVar25 = local_a8[0];
                        auVar32 = local_b8;
                        pplVar24 = pplStack_b0;
                      }
                      goto LAB_23e8495af;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x93;
                    plVar17 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (plVar17 == (longlong *)0x0) goto LAB_23e84d109;
                    if ((local_270 != (longlong *)0x0) &&
                       (lVar9 = *local_270, *local_270 = lVar9 + -1, lVar9 + -1 == 0)) {
                      (**(code **)(local_270[1] + 0x30))(local_270);
                    }
                    if ((DAT_23ed8fb50 == 0) &&
                       (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                      DAT_23ed8fb50 = 0;
                      goto LAB_23e84ddfa;
                    }
                    lVar9 = FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc88);
                    if (lVar9 == 0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_270 = plVar17;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8495af;
                    }
                    lVar16 = *(longlong *)(param_1 + 0x10);
                    plVar13 = *(longlong **)(lVar16 + 0xe18);
                    if (plVar13 == (longlong *)0x0) {
                      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
                      lVar34 = *plVar13 + 1;
                    }
                    else {
                      lVar4 = plVar13[3];
                      *(int *)(lVar16 + 0xeb8) = *(int *)(lVar16 + 0xeb8) + -1;
                      lVar34 = 2;
                      *(longlong *)(lVar16 + 0xe18) = lVar4;
                      *plVar13 = 1;
                    }
                    lVar16 = *(longlong *)
                              (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8
                              );
                    lVar4 = plVar13[-1];
                    puVar5 = *(undefined8 **)(lVar16 + 8);
                    *puVar5 = plVar13 + -2;
                    plVar13[-2] = lVar16;
                    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
                    *(longlong **)(lVar16 + 8) = plVar13 + -2;
                    plVar13[3] = lVar9;
                    *plVar13 = lVar34;
                    plVar14 = (longlong *)FUN_23ebf7b50();
                    lVar9 = DAT_23ed6cce8;
                    if (plVar14 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar20 = (longlong *)0x0;
                      local_270 = (longlong *)0x0;
                      local_1f8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8494ad;
                    }
                    lVar16 = *(longlong *)(param_1 + 0x10);
                    iVar7 = *(int *)(lVar16 + 0x1410);
                    plVar20 = *(longlong **)(DAT_23ed6cce8 + 0x20);
                    *plVar20 = *plVar20 + 1;
                    if (iVar7 == 0) {
                      local_1f8 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
                      plVar20 = *(longlong **)(lVar9 + 0x20);
                    }
                    else {
                      iVar7 = iVar7 + -1;
                      *(int *)(lVar16 + 0x1410) = iVar7;
                      local_1f8 = *(longlong **)(lVar16 + 0x1190 + (longlong)iVar7 * 8);
                      *local_1f8 = 1;
                    }
                    lVar9 = *(longlong *)(lVar9 + 0x28);
                    local_1f8[2] = 0;
                    local_1f8[3] = 1;
                    local_1f8[4] = (longlong)plVar20;
                    local_1f8[5] = lVar9;
                    iVar7 = FUN_23a35f020(plVar14);
                    pcVar15 = PyType_Type_exref;
                    if (iVar7 == -1) {
LAB_23e84e098:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar20 = (longlong *)0x0;
                      local_270 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e8494ad:
                      pplStack_b0 = pplVar24;
                      local_b8 = auVar32;
                      local_a8[0] = pplVar25;
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      local_a8[0] = (longlong **)0x0;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if ((plVar14 != (longlong *)0x0) &&
                         (lVar9 = *plVar14, *plVar14 = lVar9 + -1, lVar9 + -1 == 0)) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if ((local_1f8 != (longlong *)0x0) &&
                         (lVar9 = *local_1f8, *local_1f8 = lVar9 + -1, lVar9 + -1 == 0)) {
                        (**(code **)(local_1f8[1] + 0x30))(local_1f8);
                      }
                      if ((local_270 != (longlong *)0x0) &&
                         (lVar9 = *local_270, *local_270 = lVar9 + -1, lVar9 + -1 == 0)) {
                        (**(code **)(local_270[1] + 0x30))(local_270);
                      }
                      local_270 = plVar17;
                      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0))
                      {
                        (**(code **)(plVar20[1] + 0x30))(plVar20);
                      }
                      goto LAB_23e8495af;
                    }
                    if (iVar7 != 0) {
                      plVar20 = (longlong *)FUN_23a388650(param_1,plVar14);
                      if (plVar20 != (longlong *)0x0) {
                        pcVar15 = (code *)FUN_23e8ba4a0(plVar20[1]);
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        if (pcVar15 != (code *)0x0) goto LAB_23e848f23;
                      }
                      goto LAB_23e84e098;
                    }
                    *(longlong *)PyType_Type_exref = *(longlong *)PyType_Type_exref + 1;
LAB_23e848f23:
                    local_270 = (longlong *)FUN_23e8bc0c0(param_1,pcVar15);
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    if (local_270 == (longlong *)0x0) goto LAB_23e84e098;
                    iVar7 = FUN_23e8be270(param_1,local_270,DAT_23eedbc90);
                    if (iVar7 == -1) goto LAB_23e84e79c;
                    if (iVar7 != 0) {
                      plVar18 = (longlong *)FUN_23e8bc2f0(local_270,DAT_23eedbc90);
                      plVar20 = DAT_23eedbc98;
                      if (plVar18 != (longlong *)0x0) {
                        plVar19 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar20 = *plVar20 + 1;
                        plVar19[3] = (longlong)plVar20;
                        *plVar14 = *plVar14 + 1;
                        plVar19[4] = (longlong)plVar14;
                        *(undefined4 *)(plVar3 + 5) = 0x95;
                        plVar20 = (longlong *)FUN_23a334c60(param_1,plVar18,plVar19,local_1f8);
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          FUN_23a334bc0(plVar18);
                        }
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        if (plVar20 != (longlong *)0x0) {
                          iVar7 = FUN_23e8be270(param_1,plVar20,DAT_23eedbca0);
                          if (iVar7 == -1) {
LAB_23e8500b7:
                            auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplVar25 = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplVar24 = *(longlong ***)(param_1 + 0x68);
                          }
                          else {
                            pcVar15 = _Py_FalseStruct_exref;
                            if (iVar7 != 0) {
                              pcVar15 = _Py_TrueStruct_exref;
                            }
                            iVar7 = FUN_23a35f020(pcVar15);
                            uVar22 = DAT_23eedbca8;
                            if (iVar7 != 0) goto LAB_23e84906b;
                            lVar9 = FUN_23e8bbbe0(param_1,local_270,DAT_23ed6cd48,DAT_23eedbcb0);
                            if (lVar9 == 0) goto LAB_23e8500b7;
                            plVar18 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                            lVar16 = plVar20[1];
                            plVar18[3] = lVar9;
                            plVar19 = (longlong *)FUN_23e8ba4a0(lVar16);
                            lVar9 = FUN_23e8bc2f0(plVar19,DAT_23ed6cd48);
                            *plVar19 = *plVar19 + -1;
                            if (*plVar19 == 0) {
                              FUN_23a334bc0();
                            }
                            if (lVar9 == 0) {
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar18 = *plVar18 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar18 == 0) {
                                FUN_23a334bc0(plVar18);
                                pplVar25 = local_a8[0];
                                auVar32 = local_b8;
                                pplVar24 = pplStack_b0;
                              }
                            }
                            else {
                              plVar18[4] = lVar9;
                              plVar19 = (longlong *)FUN_23e8c2a30(uVar22,plVar18);
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                FUN_23a334bc0(plVar18);
                              }
                              pcVar15 = PyExc_TypeError_exref;
                              if (plVar19 == (longlong *)0x0) goto LAB_23e8500b7;
                              *(undefined4 *)(plVar3 + 5) = 0x95;
                              pplVar25 = (longlong **)
                                         FUN_23e914090(param_1,*(undefined8 *)pcVar15,plVar19);
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              local_b8 = (undefined1  [8])pplVar25;
                              FUN_23e91b7d0(param_1,local_b8);
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                            }
                          }
                          goto LAB_23e8494ad;
                        }
                      }
LAB_23e84e79c:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      plVar20 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8494ad;
                    }
                    plVar20 = (longlong *)FUN_23e8d6ad0(param_1);
LAB_23e84906b:
                    *plVar20 = *plVar20 + 1;
                    iVar7 = PyObject_SetItem(plVar20,DAT_23ed6cd38,DAT_23eedbcb8);
                    if ((iVar7 != 0) ||
                       (iVar7 = PyObject_SetItem(plVar20,DAT_23eedbcc8,DAT_23eedbcc0),
                       plVar18 = DAT_23eede360, iVar7 != 0)) goto LAB_23e84ebf5;
                    if (DAT_23eede360 == (longlong *)0x0) {
LAB_23e8490f8:
                      DAT_23eede360 =
                           (longlong *)FUN_23e93db80(param_1,DAT_23eede358,DAT_23eede398,0x10);
                    }
                    else {
                      lVar9 = *DAT_23eede360;
                      if (1 < lVar9) {
                        *DAT_23eede360 = lVar9 + -1;
                        goto LAB_23e8490f8;
                      }
                      if (DAT_23eede360[2] != 0) {
                        *DAT_23eede360 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar18);
                        }
                        goto LAB_23e8490f8;
                      }
                    }
                    plVar19 = DAT_23eede360;
                    FUN_23ebf7130(*(undefined8 *)(param_1 + 0x38),DAT_23eede360 + 9);
                    *plVar19 = *plVar19 + 1;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(undefined4 *)(plVar19 + 8) = 0;
                    plVar18 = DAT_23eedbcd0;
                    plVar21 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar18 = *plVar18 + 1;
                    plVar21[3] = (longlong)plVar18;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbcd8);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar21 = *plVar21 + -1;
                      if (*plVar21 == 0) {
                        FUN_23a334bc0(plVar21);
                      }
                      uVar35 = 0x97;
                      local_208 = &DAT_23ec5e407;
LAB_23e8493d6:
                      pplVar25 = local_a8[0];
                      if (local_a8[0] == (longlong **)0x0) {
                        pplVar24 = (longlong **)FUN_23e8d6280(plVar19,uVar35);
                        if ((local_a8[0] != (longlong **)0x0) &&
                           (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                           *local_a8[0] == (longlong *)0x0)) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        pplVar24 = local_a8[0];
                        if (local_a8[0][3] != plVar19) {
                          pplVar24 = (longlong **)FUN_23e8d6280(plVar19,uVar35);
                          pplVar24[2] = (longlong *)pplVar25;
                          *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                          if ((local_a8[0] != (longlong **)0x0) &&
                             (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                             *local_a8[0] == (longlong *)0x0)) {
                            FUN_23a334bc0();
                          }
                        }
                      }
                      local_a8[0] = pplVar24;
                      FUN_23e8bba40(plVar19,local_208,0,plVar17);
                      if (plVar19 == DAT_23eede360) {
                        lVar9 = *plVar19;
                        *plVar19 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        DAT_23eede360 = (longlong *)0x0;
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
LAB_23e849468:
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      _local_b8 = (undefined1  [16])0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        FUN_23a334bc0(plVar20);
                      }
                      goto LAB_23e8494ad;
                    }
                    plVar21[4] = lVar9;
                    plVar23 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),5);
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)plVar23[3] = plVar21;
                    plVar18 = DAT_23eedbce0;
                    plVar21 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar18 = *plVar18 + 1;
                    plVar21[3] = (longlong)plVar18;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbcd8);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar21 = *plVar21 + -1;
                      if (*plVar21 == 0) {
                        FUN_23a334bc0(plVar21);
                      }
                      uVar35 = 0x98;
                      local_208 = &DAT_23ec5e407;
LAB_23e854133:
                      *plVar23 = *plVar23 + -1;
                      if (*plVar23 == 0) {
                        FUN_23a334bc0(plVar23);
                      }
                      goto LAB_23e8493d6;
                    }
                    plVar21[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar23[3] + 8) = plVar21;
                    plVar18 = DAT_23eedbce8;
                    plVar21 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar18 = *plVar18 + 1;
                    plVar21[3] = (longlong)plVar18;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar21 = *plVar21 + -1;
                      if (*plVar21 == 0) {
                        FUN_23a334bc0(plVar21);
                      }
                      uVar35 = 0x99;
                      local_208 = &DAT_23ec5e407;
                      goto LAB_23e854133;
                    }
                    plVar21[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar23[3] + 0x10) = plVar21;
                    plVar18 = DAT_23eedbc18;
                    plVar21 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar18 = *plVar18 + 1;
                    plVar21[3] = (longlong)plVar18;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar21 = *plVar21 + -1;
                      if (*plVar21 == 0) {
                        FUN_23a334bc0(plVar21);
                      }
                      uVar35 = 0x9a;
                      local_208 = &DAT_23ec5e407;
                      goto LAB_23e854133;
                    }
                    plVar21[4] = lVar9;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)(plVar23[3] + 0x18) = plVar21;
                    plVar18 = DAT_23eedbcf0;
                    lVar9 = FUN_23e916ad0(uVar22,2);
                    uVar22 = DAT_23eedbcf8;
                    *plVar18 = *plVar18 + 1;
                    *(longlong **)(lVar9 + 0x18) = plVar18;
                    plVar18 = (longlong *)PyObject_GetItem(plVar20,uVar22);
                    if (plVar18 == (longlong *)0x0) {
                      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_KeyError_exref);
                      if (cVar6 == '\0') {
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar35 = 0;
                        goto LAB_23e854133;
                      }
                      *plVar17 = *plVar17 + 1;
                      plVar18 = plVar17;
                    }
                    *(longlong **)(lVar9 + 0x20) = plVar18;
                    *(longlong *)(plVar23[3] + 0x20) = lVar9;
                    iVar7 = PyObject_SetItem(plVar20,DAT_23eedbd00,plVar23);
                    *plVar23 = *plVar23 + -1;
                    if (*plVar23 == 0) {
                      FUN_23a334bc0(plVar23);
                    }
                    if (iVar7 != 0) {
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      uVar35 = 0x96;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_208 = &DAT_23ec5e407;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e8493d6;
                    }
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    iVar7 = FUN_23e9875b0(plVar14,plVar13);
                    if ((iVar7 == -1) ||
                       ((iVar7 == 1 &&
                        (iVar7 = PyObject_SetItem(plVar20,DAT_23eedbd08,plVar13), iVar7 != 0)))) {
LAB_23e84ebf5:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e849468;
                    }
                    plVar18 = DAT_23eedbc98;
                    plVar19 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                    *plVar18 = *plVar18 + 1;
                    plVar19[3] = (longlong)plVar18;
                    *plVar14 = *plVar14 + 1;
                    plVar19[4] = (longlong)plVar14;
                    *plVar20 = *plVar20 + 1;
                    plVar19[5] = (longlong)plVar20;
                    *(undefined4 *)(plVar3 + 5) = 0x95;
                    plVar18 = (longlong *)FUN_23a334c60(param_1,local_270);
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    if (plVar18 == (longlong *)0x0) goto LAB_23e84ebf5;
                    *plVar18 = *plVar18 + 1;
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    lVar9 = *plVar18;
                    *plVar18 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar18);
                    }
                    if ((local_250 != (longlong *)0x0) &&
                       (lVar9 = *local_250, *local_250 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_250);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = *plVar14;
                    *plVar14 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar9 = *local_1f8;
                    *local_1f8 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_1f8);
                    }
                    lVar9 = *local_270;
                    *local_270 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_270);
                    }
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    pcVar15 = _Py_NoneStruct_exref;
                    if (*(longlong *)_Py_NoneStruct_exref == 0) {
                      FUN_23a334bc0(_Py_NoneStruct_exref);
                    }
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22);
                    local_250 = plVar18;
                    if (lVar9 == 0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_270 = plVar17;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8495af;
                    }
                    plVar13 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),1);
                    *plVar13 = *plVar13 + 1;
                    plVar13[3] = lVar9;
                    plVar14 = (longlong *)FUN_23ebf7b50(param_1,plVar13);
                    if (plVar14 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar20 = (longlong *)0x0;
                      local_200 = (longlong *)0x0;
                      local_1f8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e853088;
                    }
                    local_1f8 = (longlong *)FUN_23e8d6ad0(param_1);
                    iVar7 = FUN_23a35f020(plVar14);
                    pcVar30 = PyType_Type_exref;
                    if (iVar7 == -1) {
LAB_23e853f56:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar20 = (longlong *)0x0;
                      local_200 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e853088:
                      pplStack_b0 = pplVar24;
                      local_b8 = auVar32;
                      local_a8[0] = pplVar25;
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      local_a8[0] = (longlong **)0x0;
                      lVar9 = *plVar13;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      *plVar13 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      if ((plVar14 != (longlong *)0x0) &&
                         (lVar9 = *plVar14, *plVar14 = lVar9 + -1, lVar9 + -1 == 0)) {
                        FUN_23a334bc0(plVar14);
                      }
                      if ((local_1f8 != (longlong *)0x0) &&
                         (lVar9 = *local_1f8, *local_1f8 = lVar9 + -1, lVar9 + -1 == 0)) {
                        FUN_23a334bc0(local_1f8);
                      }
                      if ((local_200 != (longlong *)0x0) &&
                         (lVar9 = *local_200, *local_200 = lVar9 + -1, lVar9 + -1 == 0)) {
                        FUN_23a334bc0(local_200);
                      }
                      local_270 = plVar17;
                      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0))
                      {
                        FUN_23a334bc0(plVar20);
                      }
                      goto LAB_23e8495af;
                    }
                    if (iVar7 != 0) {
                      plVar20 = (longlong *)FUN_23a388650(param_1,plVar14,DAT_23ed6ccf0);
                      if (plVar20 != (longlong *)0x0) {
                        pcVar30 = (code *)FUN_23e8ba4a0(plVar20[1]);
                        *plVar20 = *plVar20 + -1;
                        if (*plVar20 == 0) {
                          FUN_23a334bc0(plVar20);
                        }
                        if (pcVar30 != (code *)0x0) goto LAB_23e852c47;
                      }
                      goto LAB_23e853f56;
                    }
                    *(longlong *)PyType_Type_exref = *(longlong *)PyType_Type_exref + 1;
LAB_23e852c47:
                    local_200 = (longlong *)FUN_23e8bc0c0(param_1,pcVar30,plVar14);
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (local_200 == (longlong *)0x0) goto LAB_23e853f56;
                    iVar7 = FUN_23e8be270(param_1,local_200,DAT_23eedbc90);
                    if (iVar7 == -1) goto LAB_23e853ee3;
                    if (iVar7 != 0) {
                      plVar19 = (longlong *)FUN_23e8bc2f0(local_200,DAT_23eedbc90);
                      plVar20 = DAT_23eedbd10;
                      if (plVar19 != (longlong *)0x0) {
                        plVar21 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar20 = *plVar20 + 1;
                        plVar21[3] = (longlong)plVar20;
                        *plVar14 = *plVar14 + 1;
                        plVar21[4] = (longlong)plVar14;
                        *(undefined4 *)(plVar3 + 5) = 0x9e;
                        plVar20 = (longlong *)FUN_23a334c60(param_1,plVar19,plVar21,local_1f8);
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        *plVar21 = *plVar21 + -1;
                        if (*plVar21 == 0) {
                          FUN_23a334bc0(plVar21);
                        }
                        if (plVar20 != (longlong *)0x0) {
                          iVar7 = FUN_23e8be270(param_1,plVar20,DAT_23eedbca0);
                          if (iVar7 == -1) {
LAB_23e853eb5:
                            auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pplVar25 = *(longlong ***)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pplVar24 = *(longlong ***)(param_1 + 0x68);
                          }
                          else {
                            pcVar30 = _Py_FalseStruct_exref;
                            if (iVar7 != 0) {
                              pcVar30 = _Py_TrueStruct_exref;
                            }
                            iVar7 = FUN_23a35f020(pcVar30);
                            uVar22 = DAT_23eedbca8;
                            if (iVar7 != 0) goto LAB_23e852d8f;
                            lVar9 = FUN_23e8bbbe0(param_1,local_200,DAT_23ed6cd48,DAT_23eedbcb0);
                            if (lVar9 == 0) goto LAB_23e853eb5;
                            plVar18 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                            lVar16 = plVar20[1];
                            plVar18[3] = lVar9;
                            plVar19 = (longlong *)FUN_23e8ba4a0(lVar16);
                            lVar9 = FUN_23e8bc2f0(plVar19,DAT_23ed6cd48);
                            *plVar19 = *plVar19 + -1;
                            if (*plVar19 == 0) {
                              FUN_23a334bc0(plVar19);
                            }
                            if (lVar9 == 0) {
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar18 = *plVar18 + -1;
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                              if (*plVar18 == 0) {
                                FUN_23a334bc0(plVar18);
                                pplVar25 = local_a8[0];
                                auVar32 = local_b8;
                                pplVar24 = pplStack_b0;
                              }
                            }
                            else {
                              plVar18[4] = lVar9;
                              plVar19 = (longlong *)FUN_23e8c2a30(uVar22,plVar18);
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                FUN_23a334bc0(plVar18);
                              }
                              pcVar15 = PyExc_TypeError_exref;
                              if (plVar19 == (longlong *)0x0) goto LAB_23e853eb5;
                              *(undefined4 *)(plVar3 + 5) = 0x9e;
                              pplVar25 = (longlong **)
                                         FUN_23e914090(param_1,*(undefined8 *)pcVar15,plVar19);
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              local_b8 = (undefined1  [8])pplVar25;
                              FUN_23e91b7d0(param_1,local_b8);
                              pplVar25 = local_a8[0];
                              auVar32 = local_b8;
                              pplVar24 = pplStack_b0;
                            }
                          }
                          goto LAB_23e853088;
                        }
                      }
LAB_23e853ee3:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      plVar20 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e853088;
                    }
                    plVar20 = (longlong *)FUN_23e8d6ad0(param_1);
LAB_23e852d8f:
                    *plVar20 = *plVar20 + 1;
                    iVar7 = PyObject_SetItem(plVar20,DAT_23ed6cd38,DAT_23eedbcb8);
                    if ((iVar7 != 0) ||
                       (iVar7 = PyObject_SetItem(plVar20,DAT_23eedbcc8,DAT_23eedbd18),
                       plVar19 = DAT_23eede350, iVar7 != 0)) goto LAB_23e853c88;
                    if (DAT_23eede350 == (longlong *)0x0) {
LAB_23e852e15:
                      DAT_23eede350 =
                           (longlong *)FUN_23e93db80(param_1,DAT_23eede348,DAT_23eede398,0x10);
                    }
                    else {
                      lVar9 = *DAT_23eede350;
                      if (1 < lVar9) {
                        *DAT_23eede350 = lVar9 + -1;
                        goto LAB_23e852e15;
                      }
                      if (DAT_23eede350[2] != 0) {
                        *DAT_23eede350 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar19);
                        }
                        goto LAB_23e852e15;
                      }
                    }
                    plVar21 = DAT_23eede350;
                    FUN_23ebf7130(*(undefined8 *)(param_1 + 0x38),DAT_23eede350 + 9);
                    *plVar21 = *plVar21 + 1;
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(undefined4 *)(plVar21 + 8) = 0;
                    plVar19 = DAT_23ed6cf78;
                    plVar23 = (longlong *)FUN_23e916ad0(uVar22,2);
                    *plVar19 = *plVar19 + 1;
                    plVar23[3] = (longlong)plVar19;
                    uVar22 = FUN_23e9373d0();
                    lVar9 = FUN_23e8bc2f0(uVar22,DAT_23eedbc80);
                    if (lVar9 == 0) {
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar23 = *plVar23 + -1;
                      if (*plVar23 == 0) {
                        FUN_23a334bc0(plVar23);
                      }
                      uVar35 = 0xa0;
                      local_208 = &DAT_23ec5e407;
LAB_23e852fb1:
                      pplVar25 = local_a8[0];
                      if (local_a8[0] == (longlong **)0x0) {
                        pplVar24 = (longlong **)FUN_23e8d6280(plVar21,uVar35);
                        if ((local_a8[0] != (longlong **)0x0) &&
                           (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                           *local_a8[0] == (longlong *)0x0)) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        pplVar24 = local_a8[0];
                        if (local_a8[0][3] != plVar21) {
                          pplVar24 = (longlong **)FUN_23e8d6280(plVar21,uVar35);
                          pplVar24[2] = (longlong *)pplVar25;
                          *pplVar25 = (longlong *)((longlong)*pplVar25 + 1);
                          if ((local_a8[0] != (longlong **)0x0) &&
                             (*local_a8[0] = (longlong *)((longlong)*local_a8[0] + -1),
                             *local_a8[0] == (longlong *)0x0)) {
                            FUN_23a334bc0();
                          }
                        }
                      }
                      local_a8[0] = pplVar24;
                      FUN_23e8bba40(plVar21,local_208,0,plVar18);
                      if (plVar21 == DAT_23eede350) {
                        lVar9 = *plVar21;
                        *plVar21 = lVar9 + -1;
                        if (lVar9 + -1 == 0) {
                          FUN_23a334bc0(plVar21);
                        }
                        DAT_23eede350 = (longlong *)0x0;
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
LAB_23e853043:
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      _local_b8 = (undefined1  [16])0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        FUN_23a334bc0(plVar20);
                      }
                      goto LAB_23e853088;
                    }
                    plVar23[4] = lVar9;
                    plVar29 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),2);
                    uVar22 = *(undefined8 *)(param_1 + 0x10);
                    *(longlong **)plVar29[3] = plVar23;
                    plVar23 = DAT_23eedbd20;
                    lVar9 = FUN_23e916ad0(uVar22,2);
                    plVar19 = DAT_23eedbc98;
                    *plVar23 = *plVar23 + 1;
                    *(longlong **)(lVar9 + 0x18) = plVar23;
                    plVar19 = (longlong *)PyObject_GetItem(plVar20,plVar19);
                    if (plVar19 == (longlong *)0x0) {
                      cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_KeyError_exref);
                      if (cVar6 == '\0') {
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar35 = 0;
                        goto LAB_23e852fb1;
                      }
                      *plVar18 = *plVar18 + 1;
                      plVar19 = plVar18;
                    }
                    *(longlong **)(lVar9 + 0x20) = plVar19;
                    *(longlong *)(plVar29[3] + 8) = lVar9;
                    iVar7 = PyObject_SetItem(plVar20,DAT_23eedbd00);
                    *plVar29 = *plVar29 + -1;
                    if (*plVar29 == 0) {
                      FUN_23a334bc0(plVar29);
                    }
                    if (iVar7 != 0) {
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      uVar35 = 0x9f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_208 = &DAT_23ec5e407;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e852fb1;
                    }
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    iVar7 = FUN_23e9875b0(plVar14,plVar13);
                    if ((iVar7 == -1) ||
                       ((iVar7 == 1 &&
                        (iVar7 = PyObject_SetItem(plVar20,DAT_23eedbd08,plVar13), iVar7 != 0)))) {
LAB_23e853c88:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e853043;
                    }
                    plVar19 = DAT_23eedbd10;
                    plVar21 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                    *plVar19 = *plVar19 + 1;
                    plVar21[3] = (longlong)plVar19;
                    *plVar14 = *plVar14 + 1;
                    plVar21[4] = (longlong)plVar14;
                    *plVar20 = *plVar20 + 1;
                    plVar21[5] = (longlong)plVar20;
                    *(undefined4 *)(plVar3 + 5) = 0x9e;
                    plVar19 = (longlong *)FUN_23a334c60(param_1,local_200,plVar21,local_1f8);
                    *plVar21 = *plVar21 + -1;
                    if (*plVar21 == 0) {
                      FUN_23a334bc0(plVar21);
                    }
                    if (plVar19 == (longlong *)0x0) goto LAB_23e853c88;
                    *plVar19 = *plVar19 + 1;
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    lVar9 = *plVar19;
                    *plVar19 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar19);
                    }
                    if ((local_238 != (longlong *)0x0) &&
                       (lVar9 = *local_238, *local_238 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_238);
                    }
                    lVar9 = *plVar13;
                    *plVar13 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = *plVar14;
                    *plVar14 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar9 = *local_1f8;
                    *local_1f8 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_1f8);
                    }
                    lVar9 = *local_200;
                    *local_200 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(local_200);
                    }
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbc80;
                    *(undefined4 *)(plVar3 + 5) = 0xa5;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,uVar28,uVar22,
                                            *(undefined8 *)(DAT_23eedbd28 + 0x18));
                    local_238 = plVar19;
                    if (plVar13 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_270 = plVar17;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8495af;
                    }
                    if ((local_230 != (longlong *)0x0) &&
                       (lVar9 = *local_230, *local_230 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_230);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xa6;
                    plVar14 = (longlong *)FUN_23e91a870(param_1,plVar19);
                    local_230 = plVar13;
                    if (plVar14 == (longlong *)0x0) {
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_270 = plVar17;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8495af;
                    }
                    if ((local_258 != (longlong *)0x0) &&
                       (lVar9 = *local_258, *local_258 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_258);
                    }
                    cVar6 = FUN_23e8d9ac0(plVar14,DAT_23ed6cf78,DAT_23ed6ccf8);
                    plVar20 = DAT_23eedbd30;
                    pcVar15 = DAT_23ed6ccf0;
                    local_258 = plVar14;
                    if (cVar6 == '\0') {
LAB_23e853bda:
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_270 = plVar17;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e8495af;
                    }
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xa8;
                    plVar13 = (longlong *)FUN_23e915840(param_1,uVar28,uVar22,plVar13);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    *(undefined4 *)(plVar3 + 5) = 0xa8;
                    local_98 = plVar20;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar15;
                    pcStack_80 = pcVar15;
                    local_78 = plVar13;
                    plVar20 = (longlong *)FUN_23e95b390(param_1,plVar18,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar20 == (longlong *)0x0) goto LAB_23e853bda;
                    cVar6 = FUN_23e8d9ac0(plVar14,DAT_23eedbd20,plVar20);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    if (cVar6 == '\0') goto LAB_23e853bda;
                    uVar22 = FUN_23e9373d0();
                    plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    plVar20 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar20 == (longlong *)0x0) goto LAB_23e853bda;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar20,DAT_23eedbd40);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    plVar20 = DAT_23ed6ccf8;
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    pcVar15 = (code *)FUN_23e915840(param_1,uVar28,uVar22,plVar14);
                    if (pcVar15 == (code *)0x0) {
LAB_23e853b99:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      local_270 = plVar17;
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                        pplVar25 = local_a8[0];
                        auVar32 = local_b8;
                        pplVar24 = pplStack_b0;
                      }
                      goto LAB_23e8495af;
                    }
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd48;
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    pcVar30 = (code *)FUN_23e915840(param_1,uVar28,uVar22,plVar14);
                    if (pcVar30 == (code *)0x0) {
LAB_23e853b4a:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                      local_270 = plVar17;
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                      if (*(longlong *)pcVar15 == 0) {
                        FUN_23a334bc0(pcVar15);
                        pplVar25 = local_a8[0];
                        auVar32 = local_b8;
                        pplVar24 = pplStack_b0;
                      }
                      goto LAB_23e8495af;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xa9;
                    local_98 = plVar20;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar30;
                    plVar20 = (longlong *)FUN_23e956150(param_1,plVar13,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (plVar20 == (longlong *)0x0) goto LAB_23e853bda;
                    lVar9 = *plVar20;
                    *plVar20 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbd50;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) {
LAB_23e853ae3:
                      FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                      local_270 = plVar17;
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                      goto LAB_23e8495af;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xab;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    uVar22 = DAT_23eedbd58;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbd20);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    cVar6 = FUN_23e8d9ac0(plVar13,DAT_23eedbce8,uVar22);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (cVar6 == '\0') goto LAB_23e853bda;
                    uVar22 = FUN_23e9373d0();
                    plVar13 = (longlong *)FUN_23e8bc2f0(uVar22,DAT_23eedbc50);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    plVar20 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar20 == (longlong *)0x0) goto LAB_23e853bda;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar20,DAT_23eedbd40);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      FUN_23a334bc0(plVar20);
                    }
                    plVar20 = DAT_23ed6ccf8;
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd38;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    pcVar15 = (code *)FUN_23e915840(param_1,uVar28,uVar22,plVar14);
                    if (pcVar15 == (code *)0x0) goto LAB_23e853b99;
                    uVar28 = FUN_23e9373d0();
                    uVar22 = DAT_23eedbd48;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    pcVar30 = (code *)FUN_23e915840(param_1,uVar28,uVar22,plVar14);
                    if (pcVar30 == (code *)0x0) goto LAB_23e853b4a;
                    *(undefined4 *)(plVar3 + 5) = 0xaf;
                    local_98 = plVar20;
                    pcStack_90 = pcVar15;
                    local_88 = pcVar30;
                    plVar14 = (longlong *)FUN_23e956150(param_1,plVar13,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                    if (*(longlong *)pcVar15 == 0) {
                      FUN_23a334bc0(pcVar15);
                    }
                    *(longlong *)pcVar30 = *(longlong *)pcVar30 + -1;
                    if (*(longlong *)pcVar30 == 0) {
                      FUN_23a334bc0(pcVar30);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e853bda;
                    lVar9 = *plVar14;
                    *plVar14 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar9 = FUN_23e8dac20();
                    if (lVar9 == 0) goto LAB_23e853ae3;
                    *(undefined4 *)(plVar3 + 5) = 0xb1;
                    plVar13 = (longlong *)FUN_23e915840(param_1,lVar9);
                    if (plVar13 == (longlong *)0x0) goto LAB_23e853bda;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = FUN_23e8daec0();
                    if (lVar9 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e853a7d:
                      local_108 = local_a8[0];
                      local_a8[0] = (longlong **)0x0;
                      local_118 = (longlong **)local_b8;
                      pplStack_110 = pplStack_b0;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      FUN_23a35d6b0(&local_118);
                      local_270 = plVar17;
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc68);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e853a53:
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e853a7d;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0xb5;
                      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      if (plVar14 == (longlong *)0x0) goto LAB_23e853a53;
                      *plVar14 = *plVar14 + -1;
                      local_270 = plVar17;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                    }
                  }
                  lVar16 = FUN_23e8dac20();
                  lVar9 = DAT_23eedbc38;
                  uVar22 = DAT_23eedbc20;
                  if (lVar16 == 0) {
                    iVar7 = 0xbb;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xbb;
                  plVar13 = (longlong *)
                            FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0xbb;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    goto LAB_23e84a160;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  lVar9 = FUN_23e8daff0();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbbb0);
                    pplVar25 = local_a8[0];
                    auVar32 = local_b8;
                    pplVar24 = pplStack_b0;
                    goto LAB_23e84cf7a;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbbb8);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84cf4f:
                    pplVar25 = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplVar24 = *(longlong ***)(param_1 + 0x68);
LAB_23e84cf7a:
                    pplStack_b0 = pplVar24;
                    local_b8 = auVar32;
                    local_a8[0] = pplVar25;
                    local_168 = local_a8[0];
                    local_a8[0] = (longlong **)0x0;
                    local_178 = (longlong **)local_b8;
                    pplStack_170 = pplStack_b0;
                    local_b8 = (undefined1  [8])0x0;
                    pplStack_b0 = (longlong **)0x0;
                    FUN_23a35d6b0(&local_178);
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0xc3;
                    plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar1);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e84cf4f;
                    plVar13 = (longlong *)FUN_23a388310(plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e84cf4f;
                    plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                    if ((plVar14 == (longlong *)0x0) &&
                       (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_b8,0,2),
                       pplVar25 = local_a8[0], pplVar24 = pplStack_b0, auVar32 = local_b8,
                       plVar14 == (longlong *)0x0)) {
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      goto LAB_23e84cf7a;
                    }
                    plVar17 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                    if (((plVar17 == (longlong *)0x0) &&
                        (plVar17 = (longlong *)FUN_23a3c1b70(param_1,local_b8,1,2),
                        plVar17 == (longlong *)0x0)) ||
                       (cVar6 = FUN_23a3884a0(param_1,local_b8,plVar13,2), cVar6 == '\0')) {
                      pplVar25 = local_a8[0];
                      pplVar24 = pplStack_b0;
                      auVar32 = local_b8;
                      _local_b8 = (undefined1  [16])0x0;
                      local_a8[0] = (longlong **)0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      local_a8[0] = (longlong **)0x0;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0))
                      {
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                      }
                      goto LAB_23e84cf7a;
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    *plVar14 = *plVar14 + 1;
                    if ((local_278 != (longlong *)0x0) &&
                       (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_278);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    *plVar17 = *plVar17 + 1;
                    if ((local_240 != (longlong *)0x0) &&
                       (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
                      FUN_23a334bc0(local_240);
                    }
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0(plVar17);
                    }
                    uVar22 = FUN_23e9373d0();
                    plVar13 = (longlong *)FUN_23e8bc2f0(uVar22);
                    local_278 = plVar14;
                    local_240 = plVar17;
                    if (plVar13 == (longlong *)0x0) {
LAB_23e84e957:
                      pplVar25 = *(longlong ***)(param_1 + 0x70);
                      auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pplVar24 = *(longlong ***)(param_1 + 0x68);
                      goto LAB_23e84cf7a;
                    }
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e84e957;
                    *(undefined4 *)(plVar3 + 5) = 199;
                    plVar13 = (longlong *)FUN_23e915840(param_1,plVar14,DAT_23eedbd60,plVar17);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e84e957;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbd68;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                      pplVar25 = local_a8[0];
                      auVar32 = local_b8;
                      pplVar24 = pplStack_b0;
                      goto LAB_23e84cf7a;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xc9;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) goto LAB_23e84e957;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = FUN_23e8daec0();
                    if (lVar9 == 0) {
                      FUN_23e915740(param_1,local_b8);
LAB_23e84fd9c:
                      local_148 = local_a8[0];
                      local_a8[0] = (longlong **)0x0;
                      local_158 = (longlong **)local_b8;
                      pplStack_150 = pplStack_b0;
                      local_b8 = (undefined1  [8])0x0;
                      pplStack_b0 = (longlong **)0x0;
                      FUN_23a35d6b0(&local_158);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23eedbc68);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e84fd73:
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e84fd9c;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0xcd;
                      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar14 == (longlong *)0x0) goto LAB_23e84fd73;
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                    }
                  }
                  lVar9 = FUN_23e8dac20();
                  uVar22 = DAT_23eedbc20;
                  if (lVar9 == 0) {
                    iVar7 = 0xd3;
                    FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xd3;
                  plVar13 = (longlong *)FUN_23e915840(param_1,lVar9,uVar22);
                  if (plVar13 == (longlong *)0x0) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    iVar7 = 0xd3;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    goto LAB_23e84a160;
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))();
                  }
                  if ((DAT_23ed8fb50 == 0) &&
                     (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
                    DAT_23ed8fb50 = 0;
                    goto LAB_23e84ddfa;
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedbc50);
                  if (plVar13 == (longlong *)0x0) {
LAB_23e84d086:
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e84d0b1:
                    local_188 = local_a8[0];
                    local_a8[0] = (longlong **)0x0;
                    local_198 = (longlong **)local_b8;
                    pplStack_190 = pplStack_b0;
                    local_b8 = (undefined1  [8])0x0;
                    pplStack_b0 = (longlong **)0x0;
                    FUN_23a35d6b0(&local_198);
                  }
                  else {
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eedbc58);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e84d086;
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedbd70);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (plVar13 == (longlong *)0x0) goto LAB_23e84d086;
                    *(undefined4 *)(plVar3 + 5) = 0xdd;
                    pcStack_90 = _Py_TrueStruct_exref;
                    local_98 = plVar1;
                    plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar13,&local_98);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    if (plVar14 == (longlong *)0x0) goto LAB_23e84d086;
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0(plVar14);
                    }
                    lVar16 = FUN_23e8dac20();
                    lVar9 = DAT_23eedbc28;
                    uVar22 = DAT_23eedbc20;
                    if (lVar16 == 0) {
                      FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                      goto LAB_23e84d0b1;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xde;
                    plVar13 = (longlong *)
                              FUN_23e915840(param_1,lVar16,uVar22,*(undefined8 *)(lVar9 + 0x18));
                    if (plVar13 == (longlong *)0x0) goto LAB_23e84d086;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                  }
                  lVar9 = FUN_23e8daec0();
                  if (lVar9 == 0) {
                    FUN_23e915740(param_1,local_b8,DAT_23eedbb90);
LAB_23e84e1b1:
                    iVar7 = 0xe6;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xe6;
                  plVar13 = (longlong *)FUN_23e91bfe0(param_1,lVar9,DAT_23eedbc48);
                  if (plVar13 == (longlong *)0x0) {
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e84e1b1;
                  }
                  if ((local_220 != (longlong *)0x0) &&
                     (lVar9 = *local_220, *local_220 = lVar9 + -1, lVar9 + -1 == 0)) {
                    (**(code **)(local_220[1] + 0x30))(local_220);
                  }
                  iVar7 = FUN_23e912620(plVar13,plVar1);
                  local_280 = plVar13;
                  if (iVar7 == -1) {
                    local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    local_a8[0] = *(longlong ***)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    iVar7 = 0xe7;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                    goto LAB_23e84a160;
                  }
                  if (iVar7 == 1) {
                    uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
                    plVar14 = DAT_23eedbd78;
                    plVar17 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                    *plVar14 = *plVar14 + 1;
                    plVar17[3] = (longlong)plVar14;
                    plVar14 = (longlong *)FUN_23e8bf9b0(plVar12,DAT_23ed6ccf8);
                    if (plVar14 == (longlong *)0x0) {
LAB_23e84e7cd:
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        FUN_23a334bc0();
                      }
                    }
                    else {
                      lVar9 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0();
                      }
                      if (lVar9 == 0) goto LAB_23e84e7cd;
                      plVar17[4] = lVar9;
                      plVar14 = DAT_23eedbd80;
                      *DAT_23eedbd80 = *DAT_23eedbd80 + 1;
                      plVar17[5] = (longlong)plVar14;
                      plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar14 != (longlong *)0x0) {
                        *(undefined4 *)(plVar3 + 5) = 0xe8;
                        plVar17 = (longlong *)FUN_23e914090(param_1,uVar22,plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar17 != (longlong *)0x0) goto LAB_23e8503b1;
                      }
                      local_a8[0] = *(longlong ***)(param_1 + 0x70);
                      local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    iVar7 = 0xe8;
                    pplVar25 = (longlong **)_Py_NoneStruct_exref;
                    goto LAB_23e84a160;
                  }
                  plVar13 = (longlong *)FUN_23e8c5d90(plVar2,DAT_23ed6ccf8);
                  if (plVar13 != (longlong *)0x0) {
                    iVar7 = FUN_23e97c060(plVar12,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0();
                    }
                    if (iVar7 == -1) goto LAB_23e84e0d4;
                    if (iVar7 == 1) {
                      uVar28 = FUN_23a3a0d40(DAT_23ed6cf28);
                      plVar13 = DAT_23eedbd90;
                      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
                      *plVar13 = *plVar13 + 1;
                      uVar22 = DAT_23eedbd58;
                      plVar14[3] = (longlong)plVar13;
                      plVar13 = (longlong *)FUN_23e8bf9b0(plVar12,uVar22);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e84f9bc:
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        lVar9 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0();
                        }
                        if (lVar9 == 0) goto LAB_23e84f9bc;
                        plVar14[4] = lVar9;
                        plVar13 = DAT_23ed6cea0;
                        *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
                        plVar14[5] = (longlong)plVar13;
                        lVar9 = FUN_23e94f9d0(param_1,plVar2,DAT_23ed6cd28);
                        if (lVar9 == 0) goto LAB_23e84f9bc;
                        plVar14[6] = lVar9;
                        plVar13 = DAT_23eedbd98;
                        *DAT_23eedbd98 = *DAT_23eedbd98 + 1;
                        plVar14[7] = (longlong)plVar13;
                        plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar13 != (longlong *)0x0) {
                          *(undefined4 *)(plVar3 + 5) = 0xed;
                          plVar14 = (longlong *)FUN_23e914090(param_1,uVar28,plVar13);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar14 != (longlong *)0x0) {
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                            }
                            lVar16 = FUN_23e8dac20();
                            lVar9 = DAT_23eedbda0;
                            uVar22 = DAT_23eedbc20;
                            if (lVar16 == 0) {
                              FUN_23e915740(param_1,local_b8,DAT_23eedbc18);
                            }
                            else {
                              *(undefined4 *)(plVar3 + 5) = 0xee;
                              plVar13 = (longlong *)
                                        FUN_23e915840(param_1,lVar16,uVar22,
                                                      *(undefined8 *)(lVar9 + 0x18));
                              if (plVar13 != (longlong *)0x0) {
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0();
                                }
                                goto LAB_23e84a548;
                              }
                              local_a8[0] = *(longlong ***)(param_1 + 0x70);
                              local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            iVar7 = 0xee;
                            pplVar25 = (longlong **)_Py_NoneStruct_exref;
                            goto LAB_23e84a160;
                          }
                        }
                        local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pplStack_b0 = *(longlong ***)(param_1 + 0x68);
                        local_a8[0] = *(longlong ***)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      iVar7 = 0xed;
                      pplVar25 = (longlong **)_Py_NoneStruct_exref;
                      goto LAB_23e84a160;
                    }
                    goto LAB_23e84a548;
                  }
LAB_23e84e0d4:
                  local_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  local_a8[0] = *(longlong ***)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pplVar25 = (longlong **)_Py_NoneStruct_exref;
                  iVar7 = 0xec;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pplStack_b0 = *(longlong ***)(param_1 + 0x68);
LAB_23e84a160:
                  pplVar27 = local_a8[0];
                  local_1b8._8_8_ = pplStack_b0;
                  local_1b8._0_8_ = local_b8;
                  local_a8[0] = (longlong **)0x0;
                  plVar14 = *(longlong **)(param_1 + 0x138);
                  local_b8 = (undefined1  [8])0x0;
                  pplStack_b0 = (longlong **)0x0;
                  local_1a8[0] = pplVar27;
                  if (plVar14 != (longlong *)0x0) {
                    *plVar14 = *plVar14 + 1;
                  }
                  pplVar24 = (longlong **)DAT_23ed6a4f8;
                  if (pplVar27 != (longlong **)0x0) {
                    pplVar26 = local_1a8[0];
                    if (iVar7 != 0) {
                      if (DAT_23ed6a4f8 == (code *)0x0) {
                        pplVar24 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        pcVar15 = *(code **)DAT_23ed6a4f8;
                        *(undefined8 *)DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = pcVar15;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      pcVar15 = _PyRuntime_exref;
                      pplVar24[3] = plVar3;
                      *plVar3 = *plVar3 + 1;
                      lVar9 = *(longlong *)(pcVar15 + 0x1f8);
                      *(undefined4 *)(pplVar24 + 4) = 0xffffffff;
                      *(int *)((longlong)pplVar24 + 0x24) = iVar7;
                      plVar13 = *(longlong **)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
                      plVar17 = pplVar24[-1];
                      puVar5 = (undefined8 *)plVar13[1];
                      *puVar5 = pplVar24 + -2;
                      pplVar24[-2] = plVar13;
                      pplVar24[-1] = (longlong *)
                                     ((ulonglong)((uint)plVar17 & 3) | (ulonglong)puVar5);
                      plVar13[1] = (longlong)(pplVar24 + -2);
                      pplVar24[2] = (longlong *)pplVar27;
                      *pplVar27 = (longlong *)((longlong)*pplVar27 + 1);
                      pplVar26 = pplVar24;
                      if ((local_1a8[0] != (longlong **)0x0) &&
                         (*local_1a8[0] = (longlong *)((longlong)*local_1a8[0] + -1),
                         *local_1a8[0] == (longlong *)0x0)) {
                        (*(code *)local_1a8[0][1][6])();
                      }
                    }
                    goto LAB_23e84a1c3;
                  }
                  if (iVar7 == 0) {
                    iVar7 = (int)plVar3[5];
                  }
                  if (DAT_23ed6a4f8 == (code *)0x0) goto LAB_23e84b248;
                  pplVar27 = (longlong **)0x0;
                  pcVar15 = *(code **)DAT_23ed6a4f8;
                  *(undefined8 *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar15;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                } while( true );
              }
              *plVar17 = *plVar17 + 1;
              DAT_23ed6a4c0 = plVar17;
            }
            local_98 = plVar13;
            pcStack_90 = pcVar15;
            plVar14 = (longlong *)FUN_23e94ed00(param_1,plVar17,&local_98);
            if (plVar14 == (longlong *)0x0) goto LAB_23e84ad0b;
            pplVar24[6] = plVar14;
            plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pplVar24);
            *pplVar24 = (longlong *)((longlong)*pplVar24 + -1);
            if (*pplVar24 == (longlong *)0x0) {
              (*(code *)pplVar24[1][6])(pplVar24);
            }
            if (plVar14 == (longlong *)0x0) {
LAB_23e84b1d0:
              auVar32 = *(undefined1 (*) [8])(param_1 + 0x60);
              iVar7 = 0xf1;
              pplVar25 = *(longlong ***)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pplVar26 = *(longlong ***)(param_1 + 0x68);
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0xf1;
              plVar17 = (longlong *)FUN_23e914090(param_1,local_208,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar17 == (longlong *)0x0) goto LAB_23e84b1d0;
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              pplStack_b0 = (longlong **)
                            PyUnicode_FromFormat
                                      ("cannot access local variable \'%U\' where it is not associated with a value"
                                       ,DAT_23eedbd88);
              local_b8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
              *(longlong **)local_b8 = (longlong *)((longlong)*(longlong **)local_b8 + 1);
              local_a8[0] = (longlong **)0x0;
              if (local_b8 != (undefined1  [8])pplVar25) {
                FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
              }
              iVar7 = 0xf2;
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pplStack_b0);
              auVar32 = local_b8;
              pplVar26 = pplStack_b0;
              pplVar25 = local_a8[0];
            }
          }
LAB_23e84ad70:
          local_a8[0] = (longlong **)0x0;
          _local_b8 = (undefined1  [16])0x0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          pplVar24 = *(longlong ***)(param_1 + 0x138);
LAB_23e84adaf:
          *(longlong **)(param_1 + 0x138) = local_228;
          if (pplVar24 != (longlong **)0x0) goto LAB_23e84addb;
        }
LAB_23e84a740:
        local_a8[0] = (longlong **)0x0;
        _local_b8 = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
LAB_23e84a761:
        lVar9 = *plVar11;
        *plVar11 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        local_a8[0] = pplVar25;
        pplStack_b0 = pplVar26;
        local_b8 = auVar32;
        if (pplVar25 != (longlong **)0x0) {
          if (pplVar25[3] == plVar3) goto LAB_23e849cf0;
          if (iVar7 == 0) {
            iVar7 = (int)plVar3[5];
          }
          goto LAB_23e849c4a;
        }
        if (iVar7 == 0) {
          iVar7 = (int)plVar3[5];
        }
      }
    }
LAB_23e84b0cc:
    pplVar25 = (longlong **)DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pplVar25 = (longlong **)FUN_23a33a530(PyTraceBack_Type_exref);
      pplVar24 = local_a8[0];
    }
    else {
      pcVar15 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pplVar24 = (longlong **)0x0;
    }
    pcVar15 = _PyRuntime_exref;
    pplVar25[2] = (longlong *)0x0;
    pplVar25[3] = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)(pplVar25 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(int *)((longlong)pplVar25 + 0x24) = iVar7;
    plVar11 = *(longlong **)(lVar9 + 0x2e8);
    plVar13 = pplVar25[-1];
    puVar5 = (undefined8 *)plVar11[1];
    *puVar5 = pplVar25 + -2;
    pplVar25[-2] = plVar11;
    pplVar25[-1] = (longlong *)((ulonglong)((uint)plVar13 & 3) | (ulonglong)puVar5);
    plVar11[1] = (longlong)(pplVar25 + -2);
  }
  if ((pplVar24 != (longlong **)0x0) &&
     (*pplVar24 = (longlong *)((longlong)*pplVar24 + -1), *pplVar24 == (longlong *)0x0)) {
    (*(code *)pplVar24[1][6])();
  }
LAB_23e849cf0:
  local_a8[0] = pplVar25;
  FUN_23e8bba40(plVar3,"ooooooooooooooo",plVar1,plVar2,plVar10,local_280,local_260,local_278,
                local_268,local_248,0,local_270,local_250,local_238,local_230,local_258,local_240);
  if (DAT_23eede370 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eede370 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  plVar11 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pplVar24 = local_a8[0];
  pplVar25 = pplStack_b0;
  auVar32 = local_b8;
  plVar3[0xf] = 0;
  _local_b8 = (undefined1  [16])0x0;
  local_a8[0] = (longlong **)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((local_280 != (longlong *)0x0) &&
     (lVar9 = *local_280, *local_280 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_280[1] + 0x30))(local_280);
  }
  if ((local_260 != (longlong *)0x0) &&
     (lVar9 = *local_260, *local_260 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_260[1] + 0x30))(local_260);
  }
  if ((local_278 != (longlong *)0x0) &&
     (lVar9 = *local_278, *local_278 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_278[1] + 0x30))(local_278);
  }
  if ((local_268 != (code *)0x0) &&
     (lVar9 = *(longlong *)local_268, *(longlong *)local_268 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_268 + 8) + 0x30))(local_268);
  }
  if ((local_248 != (longlong *)0x0) &&
     (lVar9 = *local_248, *local_248 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_248[1] + 0x30))(local_248);
  }
  if ((local_270 != (longlong *)0x0) &&
     (lVar9 = *local_270, *local_270 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_270[1] + 0x30))(local_270);
  }
  if ((local_250 != (longlong *)0x0) &&
     (lVar9 = *local_250, *local_250 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_250[1] + 0x30))(local_250);
  }
  if ((local_238 != (longlong *)0x0) &&
     (lVar9 = *local_238, *local_238 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_238[1] + 0x30))(local_238);
  }
  if ((local_230 != (longlong *)0x0) &&
     (lVar9 = *local_230, *local_230 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_230[1] + 0x30))(local_230);
  }
  if ((local_258 != (longlong *)0x0) &&
     (lVar9 = *local_258, *local_258 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_258[1] + 0x30))(local_258);
  }
  if ((local_240 != (longlong *)0x0) &&
     (lVar9 = *local_240, *local_240 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_240[1] + 0x30))(local_240);
  }
  _local_b8 = CONCAT88(pplVar25,auVar32);
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  local_a8[0] = pplVar24;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar9 = *plVar2;
  *plVar2 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_b8,pplStack_b0,local_a8[0]);
  return (code *)0x0;
}
